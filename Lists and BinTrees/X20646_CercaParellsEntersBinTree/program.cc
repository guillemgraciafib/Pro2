#include "BinTreeIOParInt.hh"
#include <iostream>

void CercaBinTree(BinTree<ParInt>& a, int n, int& counter, bool& trobat){
    if(!a.empty() and not trobat){
        if(a.value() == n){
            trobat = true;
            cout << n << ' ' << a.value().segon() << ' ' << counter << endl;
        }
        else{
            ++counter;
            CercaBinTree(a.left(), n, counter, trobat);
            CercaBinTree(a.right(), n, counter, trobat);
            --counter;
        }
    }
    else if(not trobat and counter == 0) cout << "-1" << endl;
}

int main{
    BinTree<ParInt> a;
    read_bintree_parint(a);
    int n;
    while(cin >> n){
        bool trobat = false;
        int counter = 0;
        CercaBinTree(a,n,counter,trobat)
    }
}