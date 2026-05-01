#include "Trie.h"

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
