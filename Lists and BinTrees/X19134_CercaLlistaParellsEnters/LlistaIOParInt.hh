#include <list>
#include "ParInt.hh"

class LlistaIOParInt {
public:
    // Pre: l és buida; el canal estandar d’entrada conté un nombre
    // parell d’enters, acabat pel parell 0 0
    // Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
    void LlegirLlistaParInt(list<ParInt>&);
    
    // Pre: cert
    // Post: s’han escrit al canal estandar de sortida els elements de l
    void EscriureLlistaParInt(const list<ParInt>&);
    
};