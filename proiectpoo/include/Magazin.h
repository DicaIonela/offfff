#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <vector>
#include "Subprodus.h"

using namespace std;

class Magazin {
private:
    vector<Subprodus> listaSubproduse;

public:
    void adaugaSubprodus(const Subprodus& subprodus);
    void afiseazaSubproduse() const;
    bool salveazaSubproduseInFisier(const string& numeFisier) const;
    bool incarcaSubproduseDinFisier(const string& numeFisier);
};

#endif // MAGAZIN_H
