#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void appliquerFiltre(vector<int>& vec, function<void(int&, int)> filtre) {
    int seuil = 0;
    cout << "Donner seuil: ";
    if (filtre.target_type().name() == typeid(function<void(int&, int)>).name()) {
        cin >> seuil;
    }

    for (int& e : vec) {
        filtre(e, seuil);
    }
    cout << endl;
}

int main() {
    vector<int> tab{ -2, 3, -33, 7, 99, 6, 2, -39 };
    cout << "************************\n";
    cout << "* 1. Afficher positif  *\n";
    cout << "* 2. Afficher negatif  *\n";
    cout << "* 3. Superieur A       *\n";
    cout << "************************\n";
    cout << "Entrez votre choix: ";

    int choix;
    cin >> choix;

    auto afficherPositif = [](int& x, int seuil = 0) {
        if (x >= 0)
            cout << x << "\t";
    };

    auto afficherNegatif = [](int& x, int seuil = 0) {
        if (x < 0)
            cout << x << "\t";
    };

    auto superieurA = [](int& x, int seuil) {
        if (x >= seuil)
            cout << x << "\t";
    };

    switch (choix) {
        case 1:
            appliquerFiltre(tab, afficherPositif);
            break;
        case 2:
            appliquerFiltre(tab, afficherNegatif);
            break;
        case 3:
            appliquerFiltre(tab, superieurA);
            break;
        default:
            cout << "Choix non valide." << endl;
            break;
    }

    return 0;
}
