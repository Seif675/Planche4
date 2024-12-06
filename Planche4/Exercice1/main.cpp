#include <iostream>
#include <array>

template <typename T>
void echanger(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void trier(std::array<T, 10> &tableau) {
    int taille = tableau.size();

    for (int i = 0; i < taille - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < taille; ++j) {
            if (tableau[j] < tableau[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            echanger(tableau[i], tableau[minIndex]);
        }
    }
}

template <typename T>
void afficher(const std::array<T, 10> &tableau) {
    for (const auto &elem : tableau) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 10> tableauInt = {10, 3, 6, 1, 8, 4, 2, 9, 5, 7};
    std::cout << "Tableau avant le tri : ";
    afficher(tableauInt);

    trier(tableauInt);
    std::cout << "Tableau apres le tri : ";
    afficher(tableauInt);

    std::array<float, 10> tableauFloat = {3.5, 2.1, 4.2, 1.9, 0.5, 7.8, 6.3, 8.0, 5.4, 9.1};
    std::cout << "Tableau avant le tri : ";
    afficher(tableauFloat);

    trier(tableauFloat);
    std::cout << "Tableau apres le tri : ";
    afficher(tableauFloat);

    return 0;
}
