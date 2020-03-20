#include "CuaIOParInt.hh"

void CuaIOParInt::llegirCuaParInt(queue<ParInt>& c) {
    ParInt currentParInt;

    currentParInt.llegir();
    while(currentParInt.primer != 0 && currentParInt.segon != 0) {
        c.push(currentParInt);
        currentParInt.llegir();
    }
}

void CuaIOParInt::escriureCuaParInt(queue<ParInt> c) {
    while(!c.empty()) {
        c.front().escriure();
        c.pop();
    }
}