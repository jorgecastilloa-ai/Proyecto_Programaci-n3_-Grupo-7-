#include "Movie.h"

Movie::Movie(string t, string p, string g, string d, string c) {
    title = t;
    plot = p;
    genre = g;
    director = d;
    cast = c;
    likes = 0;
    views = 0;
}

string Movie::getTitle() { return title; }
string Movie::getPlot() { return plot; }
string Movie::getGenre() { return genre; }
string Movie::getDirector() { return director; }
string Movie::getCast() { return cast; }

void Movie::addLike() { likes++; }
void Movie::addView() { views++; }

int Movie::getScore(int matches) {
    return matches * 10 + likes * 5 + views;
}
