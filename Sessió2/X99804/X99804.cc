#include "Estudiant.hh"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool mySortingFuncion (Estudiant std1, Estudiant std2) {
    if (std1.te_nota() and std2.te_nota()) {
        if (std1.consultar_nota() == std2.consultar_nota()) {
            return std1.consultar_DNI() < std2.consultar_DNI();
        }

       return std1.consultar_nota() > std2.consultar_nota();
    }
    else if (std1.te_nota()) {
        return false;
    }
    else if (std2.te_nota()) {
        return true;
    }
    return false;
}

int main () {
    int numeroEstudiants;
    int numeroAssignatures;
    int numeroAssignaturesSeleccionades;
    
    cin >> numeroEstudiants >> numeroAssignatures >> numeroAssignaturesSeleccionades;
    
    vector<bool> AssignaturesSeleccionades (numeroAssignatures, false);
    
    for (int i = 0; i < numeroAssignaturesSeleccionades; ++i) {
        int aux;
        cin >> aux;
        AssignaturesSeleccionades[(aux - 1)] = true;
    }
    
    vector <Estudiant> Estudiants (numeroEstudiants);
    
    for (int i = 0; i < numeroEstudiants; ++i) {
        int DNI;
        cin >> DNI;
        
        double mitjana = 0;
        for (int i = 0; i < numeroAssignatures; ++i) {
            double aux; 
            cin >> aux;
            if (AssignaturesSeleccionades[i]) mitjana += aux;
        }
        
        mitjana = mitjana / numeroAssignaturesSeleccionades;
        Estudiant est(DNI);
        est.afegir_nota(mitjana);
        Estudiants[i]= est;
    }
    
    sort (Estudiants.begin(), Estudiants.end(), mySortingFuncion);

    for (int i = 0; i < numeroEstudiants; ++i) {
        Estudiants[i].escriure();
    }
    
}