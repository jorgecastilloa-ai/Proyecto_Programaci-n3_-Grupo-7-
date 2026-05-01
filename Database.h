#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include "Movie.h"
#include "Trie.h"

class Database {
private:
    vector<Movie*> movies;
    Trie trie;

public:
    void loadCSV(string filename);
    vector<Movie*> search(string query);
};

#endif
