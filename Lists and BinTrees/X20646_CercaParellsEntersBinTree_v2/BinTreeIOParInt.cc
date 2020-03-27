#include "BinTreeIOParInt.hh"

void read_bintree_est(BinTree<ParInt>& a) {
	ParInt temp;

	if (temp.llegir()) {
		BinTree<ParInt> tl;
		BinTree<ParInt> tr;

		read_bintree_est(tl);
		read_bintree_est(tr);

		a = BinTree<ParInt>(temp, tl, tr);
	}
}

void write_bintree_est(const BinTree<ParInt>& a) {

}