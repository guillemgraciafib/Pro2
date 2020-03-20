#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std;

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
    
    for (int i = 0; i < numeroEstudiants; ++i) {
        Estudiants[i].escriure();
    }
    
}