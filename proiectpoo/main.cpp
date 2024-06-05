#include <iostream>
#include "Magazin.h"

using namespace std;

int main() {
    Magazin magazin;

    Subprodus subprodus1("Categorie1", 1, "Subprodus1", 100, 10);
    Subprodus subprodus2("Categorie2", 2, "Subprodus2", 200, 20);

    magazin.adaugaSubprodus(subprodus1);
    magazin.adaugaSubprodus(subprodus2);

    magazin.afiseazaSubproduse();

    magazin.salveazaSubproduseInFisier("subproduse.txt");

    Magazin magazinNou;
    magazinNou.incarcaSubproduseDinFisier("subproduse.txt");
    magazinNou.afiseazaSubproduse();

    return 0;
}
