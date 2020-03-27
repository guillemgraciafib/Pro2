#include "BinTree.hh"
#include "ParInt.hh"

void read_bintree_est(BinTree<ParInt>& a);
// Pre: a és buit; el canal estandar d’entrada conté una seqüència
// de parells <int, double> que representa un arbre binari d’estudiants
// en preordre, on un parell amb l’int = ‘‘marca’’ representa
// un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada

void write_bintree_est(const BinTree<ParInt>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorreguts en inordre, a = A