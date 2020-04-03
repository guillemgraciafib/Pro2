#include "BinTreeIOEst.hh"

Estudiant CercaEstudiant(const BinTree<Estudiant>& tree, int dni, int& profunditat) {
	Estudiant est;

	if (tree.empty()) {
		profunditat = -1;
	}
	else if (tree.value().consultar_DNI() == dni) {
		est = tree.value();
		profunditat = 0;
	}
	else {
		est = CercaEstudiant(tree.left(), dni, profunditat);
		if (profunditat == -1) {
			est = CercaEstudiant(tree.right(), dni, profunditat);
		}
		if (profunditat != -1) {
			profunditat++;
		}
	}

	return est;
}

int main() {
	BinTree<Estudiant>tree;
	read_bintree_est(tree);

	int current;
	while (cin >> current) {
		int profunditat = 0;
		Estudiant temp = CercaEstudiant(tree, current, profunditat);

		cout << current << " " << profunditat;
		if (profunditat != -1) {
			cout << " ";
			if (temp.te_nota()) {
				cout << temp.consultar_nota() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else {
			cout << endl;
		}
	}
}