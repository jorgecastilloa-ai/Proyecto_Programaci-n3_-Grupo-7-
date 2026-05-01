#ifndef USER_H
#define USER_H
#include <vector>
#include "Movie.h"

class User {
private:
    vector<Movie*> liked;
    vector<Movie*> watchLater;

public:
    void like(Movie* m);
    void addWatchLater(Movie* m);
    vector<Movie*> getLiked();
    vector<Movie*> getWatchLater();
};

#endif
