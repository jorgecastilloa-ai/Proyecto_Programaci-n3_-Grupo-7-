#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;

class Movie {
private:
    string title, plot, genre, director, cast;
    int likes, views;

public:
    Movie(string t, string p, string g, string d, string c);
    string getTitle();
    string getPlot();
    string getGenre();
    string getDirector();
    string getCast();
    void addLike();
    void addView();
    int getScore(int matches);
};

#endif
