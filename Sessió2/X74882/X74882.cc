#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;

int main () {
    
    Cjt_estudiants PrimerConjunt;
    PrimerConjunt.llegir();    

    Cjt_estudiants SegonConjunt;
    SegonConjunt.llegir();

    for (int i = 1; i <= PrimerConjunt.mida(); ++i) {
        Estudiant std = PrimerConjunt.consultar_iessim(i);
        Estudiant std2 = SegonConjunt.consultar_estudiant(std.consultar_DNI());

        if (std.te_nota()) {
            if (std2.te_nota() and (std.consultar_nota() < std2.consultar_nota())) {
                PrimerConjunt.modificar_iessim(i, std2);
            }
        }

        else if (std2.te_nota()) {
            PrimerConjunt.modificar_iessim(i, std2);
        }
    }

    PrimerConjunt.escriure();
}