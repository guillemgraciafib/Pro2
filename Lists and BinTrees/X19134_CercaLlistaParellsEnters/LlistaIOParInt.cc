#include "LlistaIOParInt.hh"


void LlistaIOParInt::LlegirLlistaParInt(list<ParInt>& llista) {
    ParInt temp;

    temp.llegir();

    while(temp.primer() != 0 && temp.segon() != 0) {
        llista.push_back(temp);
        temp.llegir();
    }
    llista.push_back(temp);
}

void LlistaIOParInt::EscriureLlistaParInt(const list<ParInt>& llista) {
    int size = llista.size();

    for(list<ParInt>::const_iterator it = llista.begin(); it != llista.end(); ++it) {
        it->escriure(); //tambien puede ser (*it).escriure(), pero mejor como yo lo he puesto
    }
}