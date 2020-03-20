#ifndef CUA_IO_PAR_INT_HH
#define CUA_IO_PAR_INT_HH

#include "ParInt.hh"
#include <queue>

class CuaIOParInt {
public:
    CuaIOParInt();
    ~CuaIOParInt();

    // Pre: c és buida; el canal estandar d’entrada conté un nombre
    // parell d’enters, acabat pel parell 0 0
    // Post: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)
    void llegirCuaParInt(queue<ParInt>& c);
   
    // Pre: cert
    // Post: s’han escrit al canal estandar de sortida els elements de c
    void escriureCuaParInt(queue<ParInt> c);
    
};

#endif