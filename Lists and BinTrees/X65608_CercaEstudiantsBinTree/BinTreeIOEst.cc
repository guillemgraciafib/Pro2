#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a) {
    Estudiant est;
    est.llegir();

    if(est.consultar_DNI() != 0) {
        BinTree<Estudiant> estL;
        BinTree<Estudiant> estR;

        read_bintree_est(estL);
        read_bintree_est(estR);

        a = BinTree<Estudiant>(est, estL, estR);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a) {
    
}