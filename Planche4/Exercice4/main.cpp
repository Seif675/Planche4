#include <iostream>
#include <string>

using namespace std;

struct Produit {
    string type;
    double prixHT;
    bool solde;
};

double calculerPrix(const Produit& produit) {
    double taxe = 0.19;
    if (produit.type == "luxe") {
        taxe = 0.25;
    }

    double prixTTC = produit.prixHT * (1 + taxe);

    if (produit.solde) {
        prixTTC *= 0.80;
    }

    return prixTTC;
}

int main() {
    Produit produit1{"standard", 100.0, false};
    Produit produit2{"luxe", 200.0, true};
    Produit produit3{"standard", 150.0, true};
    Produit produit4{"luxe", 500.0, false};

    cout << "Prix net du produit 1: " << calculerPrix(produit1) << " euros" << endl;
    cout << "Prix net du produit 2: " << calculerPrix(produit2) << " euros" << endl;
    cout << "Prix net du produit 3: " << calculerPrix(produit3) << " euros" << endl;
    cout << "Prix net du produit 4: " << calculerPrix(produit4) << " euros" << endl;

    return 0;
}
