#ifndef TRIE_H
#define TRIE_H
#include <map>
#include <vector>
#include <string>
#include "Movie.h"
using namespace std;


class TrieNode {
public:
    map<char, TrieNode*> children;
    vector<Movie*> movies;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(string word, Movie* movie);
    vector<Movie*> search(string word);
    vector<Movie*> searchSubstring(string word);

};

#endif
