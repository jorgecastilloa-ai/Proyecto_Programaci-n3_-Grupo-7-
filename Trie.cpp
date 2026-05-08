#include "Trie.h"
#include <algorithm>


Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word, Movie* movie) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c])
            node->children[c] = new TrieNode();
        node = node->children[c];
        node->movies.push_back(movie);
    }
}

vector<Movie*> Trie::search(string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c])
            return {};
        node = node->children[c];
    }
    return node->movies;
}

void collectMovies(TrieNode* node, vector<Movie*>& result) {
    for (auto& child : node->children) {
        for (auto* m : child.second->movies) {
            if (find(result.begin(), result.end(), m) == result.end())
                result.push_back(m);
        }
        collectMovies(child.second, result);
    }
}

vector<Movie*> Trie::searchSubstring(string word) {
    vector<Movie*> result;
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c]) return {};
        node = node->children[c];
    }
    result = node->movies;
    return result;
}