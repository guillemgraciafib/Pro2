#include "BinTreeIOParInt.hh"
#include <iostream>

ParInt CercaParella(const BinTree<ParInt>& tree, const int num) {
	ParInt temp;

	if (tree.empty() || tree.value().primer() == 0 && tree.value().segon() == 0) {
		temp = ParInt(0, -1);
	}
	else if (tree.value().primer() == num) {
		temp = ParInt(tree.value().segon(), 0);
	}
	else {
		temp = CercaParella(tree.left(), num);
		if (temp.primer() == 0 && temp.segon() == -1) {
			temp = CercaParella(tree.right(), num);
		}

		if (temp.segon() != -1) {
			temp = ParInt(temp.primer(), temp.segon() + 1);
		}
	}

	return temp;
}

int main() {
	BinTree<ParInt>tree;
	read_bintree_est(tree);

	int current;

	while (cin >> current) {
		ParInt temp = CercaParella(tree, current);
		if (temp.segon() != -1) {
			cout << current << " " << temp.primer() << " " << temp.segon() << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
}