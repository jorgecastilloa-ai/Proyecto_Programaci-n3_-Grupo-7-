#include "Utils.h"
#include "User.h"
#include <map>
#include <algorithm>
using namespace std;

void User::like(Movie* m) {
    liked.push_back(m);
    m->addLike();
}

void User::addWatchLater(Movie* m) {
    watchLater.push_back(m);
}

vector<Movie*> User::getLiked() { return liked; }
vector<Movie*> User::getWatchLater() { return watchLater; }

vector<Movie*> User::getSimilar(vector<Movie*>& allMovies) {
    if (liked.empty()) return {};

    map<string, int> genreScore;
    map<string, int> wordScore;

    for (auto* m : liked) {
        vector<string> genres = splitWords(toLower(m->getGenre()));
        for (auto& g : genres) genreScore[g]++;

        vector<string> words = splitWords(toLower(m->getTitle()));
        for (auto& w : words)
            if (w.length() > 3) wordScore[w]++;
    }

    map<Movie*, int> scoreMap;
    for (auto* m : allMovies) {
        if (find(liked.begin(), liked.end(), m) != liked.end()) continue;

        vector<string> genres = splitWords(toLower(m->getGenre()));
        for (auto& g : genres)
            if (genreScore.count(g)) scoreMap[m] += genreScore[g] * 100;

        vector<string> words = splitWords(toLower(m->getTitle()));
        for (auto& w : words)
            if (w.length() > 3 && wordScore.count(w)) scoreMap[m] += wordScore[w] * 5;
    }

    vector<pair<Movie*, int>> temp(scoreMap.begin(), scoreMap.end()); //los ordenamos por su score
    sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    vector<Movie*> result;
    int limit = min(5, (int)temp.size());
    for (int i = 0; i < limit; i++)
        result.push_back(temp[i].first);

    return result;
}