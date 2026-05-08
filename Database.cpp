#include "Database.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> parseCSVLine(const string& line) {

    vector<string> result;
    string current;
    bool inQuotes = false;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }

    result.push_back(current);
    return result;
}

void Database::loadCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: no se abrio el archivo" << endl;
        return;
    }

    string line, fullLine;
    getline(file, line);

    int count = 0;
    while (getline(file, line)) {
        fullLine += line;

        int quotes = 0;
        for (char c : fullLine) {
            if (c == '"') quotes++;
        }

        if (quotes % 2 != 0) {
            fullLine += "\n";
            continue;
        }

        vector<string> fields = parseCSVLine(fullLine);
        fullLine = "";

        if (fields.size() < 8) continue;

        string title    = fields[1];
        string director = fields[3];
        string cast     = fields[4];
        string genre    = fields[5];
        string plot     = fields[7];

        Movie* m = new Movie(title, plot, genre, director, cast);
        movies.push_back(m);

        string content = toLower(title + " " + plot + " " + genre + " " + director + " " + cast);
        vector<string> words = splitWords(content);

        for (auto& w : words) {
            trie.insert(w, m);
        }
        count++;
    }
}

vector<Movie*> Database::search(string query) {
    query = toLower(query);
    vector<string> words = splitWords(query);
    map<Movie*, int> scoreMap;

    for (auto& w : words) {
        vector<Movie*> results = trie.searchSubstring(w);
        for (auto* m : results) {
            if (toLower(m->getTitle()).find(w) != string::npos)
                scoreMap[m] += 20; //tremenda diferencia para que valga el titulo sobretodo
            else
                scoreMap[m] += 1;
        }
    }

    vector<pair<Movie*, int>> temp(scoreMap.begin(), scoreMap.end());
    sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
        return a.first->getScore(a.second) > b.first->getScore(b.second);
    });

    vector<Movie*> result;
    for (auto& p : temp) result.push_back(p.first);
    return result;
}