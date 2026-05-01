#include "Database.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

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
    string line;

    getline(file, line);

    while (getline(file, line)) {
        vector<string> fields = parseCSVLine(line);
        if (fields.size() < 8) continue;

        string title = fields[1];
        string director = fields[3];
        string cast = fields[4];
        string genre = fields[5];
        string plot = fields[7];

        Movie* m = new Movie(title, plot, genre, director, cast);
        movies.push_back(m);

        string content = toLower(title + " " + plot + " " + genre + " " + director + " " + cast);
        vector<string> words = splitWords(content);

        for (auto& w : words) {
            trie.insert(w, m);
        }
    }
}

vector<Movie*> Database::search(string query) {
    query = toLower(query);
    vector<string> words = splitWords(query);
    map<Movie*, int> scoreMap;

    for (auto& w : words) {
        vector<Movie*> results = trie.search(w);
        for (auto* m : results) {
            scoreMap[m]++;
        }
    }

    vector<pair<Movie*, int>> temp(scoreMap.begin(), scoreMap.end());

    sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
        return a.first->getScore(a.second) > b.first->getScore(b.second);
    });

    vector<Movie*> result;
    for (auto& p : temp) {
        result.push_back(p.first);
    }

    return result;
}
