#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l){
    int dni = -1;
    double nota = -1;
    while(dni != 0 and nota != 0){
        cin >> dni >> nota;
        Estudiant est(dni);
        est.afegir_nota(nota);
        l.push_back(est);
    }
}

//void EscriureLlistaEstudiant(list<Estudiant>& l){


//}