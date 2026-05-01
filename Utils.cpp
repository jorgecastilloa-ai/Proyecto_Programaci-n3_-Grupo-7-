#include "Utils.h"
#include <sstream>
#include <algorithm>
#include <cctype>

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

vector<string> splitWords(string text) {
    vector<string> words;
    string clean;

    for (char c : text) {
        if (isalnum(c) || c == ' ')
            clean += c;
        else
            clean += ' ';
    }

    stringstream ss(clean);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}
