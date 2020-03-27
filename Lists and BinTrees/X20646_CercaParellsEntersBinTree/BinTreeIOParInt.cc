#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a){
    ParInt p;
    p.llegir();
    if(p.primer() != 0 and p.segon() != 0){
        BinTree<ParInt> esq;
        BinTree<ParInt> dreta;
        read_bintree_parint(esq);
        read_bintree_parint(dreta);
        a = BinTree<ParInt>(p,esq,dreta);
    }
}

void write_bintree_parint(const BinTree<ParInt>& a){
    if(!a.empty()){
        write_bintree_parint(a.right());
        a.value().escriure();
        write_bintree_parint(a.left());
    }
}