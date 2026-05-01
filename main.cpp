#include <iostream>
#include <algorithm>
#include "Database.h"
#include "User.h"

using namespace std;

int main() {
    Database db;
    User user;

    db.loadCSV("wiki_movie_plots_deduped.csv");

    while (true) {
        cout << "\n1. Buscar pelicula\n2. Lista ver más tarde\n3. Salir\n";
        int op;
        cin >> op;
        cin.ignore();

        if (op == 1) {
            string query;
            cout << "Buscar: ";
            getline(cin, query);

            auto results = db.search(query);
            int page = 0;

            while (true) {
                int start = page * 5;
                int end = min(start + 5, (int)results.size());

                if (start >= results.size()) {
                    cout << "No hay más resultados.\n";
                    break;
                }

                for (int i = start; i < end; i++) {
                    cout << i << ". "
                         << results[i]->getTitle()
                         << " | Director: " << results[i]->getDirector()
                         << " | Genero: " << results[i]->getGenre()
                         << endl;
                }

                cout << "\nSelecciona índice, -1 siguiente página, -2 salir: ";
                int idx;
                cin >> idx;

                if (idx == -1) {
                    page++;
                    continue;
                } else if (idx == -2) {
                    break;
                } else if (idx >= 0 && idx < results.size()) {
                    auto m = results[idx];
                    m->addView();

                    cout << "\nSINOPSIS:\n" << m->getPlot() << endl;

                    cout << "\n1. Like\n2. Ver más tarde\nOtro número para volver\n";
                    int op2;
                    cin >> op2;

                    if (op2 == 1) user.like(m);
                    else if (op2 == 2) user.addWatchLater(m);

                    break;
                }
            }
        } else if (op == 2) {
            auto wl = user.getWatchLater();

            if (wl.empty()) {
                cout << "No hay películas guardadas.\n";
            }

            for (auto* m : wl) {
                cout << "- " << m->getTitle()
                     << " | Director: " << m->getDirector()
                     << endl;
            }
        } else {
            break;
        }
    }

    return 0;
}
