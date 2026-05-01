#include "User.h"

void User::like(Movie* m) {
    liked.push_back(m);
    m->addLike();
}

void User::addWatchLater(Movie* m) {
    watchLater.push_back(m);
}

vector<Movie*> User::getLiked() { return liked; }
vector<Movie*> User::getWatchLater() { return watchLater; }
