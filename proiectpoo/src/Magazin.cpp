#include "Magazin.h"
#include <iostream>
#include <fstream>

using namespace std;

void Magazin::adaugaSubprodus(const Subprodus& subprodus) {
    listaSubproduse.push_back(subprodus);
}

void Magazin::afiseazaSubproduse() const {
    cout << "Subprodusele din magazin sunt:" << endl;
    for (const auto& subprodus : listaSubproduse) {
        cout << subprodus << endl;
    }
}

bool Magazin::salveazaSubproduseInFisier(const string& numeFisier) const {
    ofstream fisier(numeFisier);
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fișierului pentru scriere: " << numeFisier << endl;
        return false;
    }

    for ( auto& subprodus : listaSubproduse) {
        fisier << subprodus.getNumeProdus() << " "
               << subprodus.getCodCategorie() << " "
               << subprodus.getNumeSubprodus() << " "
               << subprodus.getgreutate() << " "
               << subprodus.getnrproduse() << endl;
    }

    fisier.close();
    return true;
}

bool Magazin::incarcaSubproduseDinFisier(const string& numeFisier) {
    ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fișierului pentru citire: " << numeFisier << endl;
        return false;
    }

    listaSubproduse.clear();

    string numeProdus;
    int codCategorie;
    char numeSubprodus[30];
    int greutate;
    int nrproduse;

    while (fisier >> numeProdus >> codCategorie >> numeSubprodus >> greutate >> nrproduse) {
        Subprodus subprodus(numeProdus.c_str(), codCategorie, numeSubprodus, greutate, nr
