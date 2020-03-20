#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main () {
    int repeticions;
    cin >> repeticions;

    vector <Estudiant> estudiants(0);
    for (int i = 0; i < repeticions; ++i) {
        int dni;
        double nota;
        cin >> dni >> nota;
        cout << i << "1" << endl;
        
        if (i == 0 or estudiants[estudiants.size() - 1].consultar_DNI() != dni) {
            estudiants.push_back(dni);
            estudiants[estudiants.size() - 1].afegir_nota(nota);
            cout << i << "2" << endl;

        }

        else {
            if (estudiants[estudiants.size() - 1].te_nota() and estudiants[estudiants.size() - 1].consultar_nota() < nota) {
                estudiants[estudiants.size() - 1].modificar_nota(nota);
                cout << i << "3" << endl;
            }
        }
    }
    for (int i = 0; i < estudiants.size(); ++i) {
        cout << estudiants[i].consultar_DNI() << ' ' << estudiants[i].consultar_nota() << endl; 
    }    
}