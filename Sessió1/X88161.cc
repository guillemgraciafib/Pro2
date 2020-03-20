#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct partits {
	int local;
	int visitant;
};
typedef vector <partits> LligaPre;
typedef vector < LligaPre > Lliga;

struct classificacio {
	int equip;
	int punts;
	int golsMarcats;
	int golsRebuts;
};
typedef vector <classificacio> Equips;

void lecturaDades(Lliga& League, int numeroEquips) {
	for (int i = 0; i < numeroEquips; ++i) {
		for (int j = 0; j < numeroEquips; ++j) {
			cin >> League[j][i].local >> League[j][i].visitant;
		}
	}
}

void procesDades(Lliga& League, int numeroEquips, Equips& Classificacio) {
	for (int i = 0; i < numeroEquips; ++i) {
		Classificacio[i].equip = (i + 1);

		for (int j = 0; j < numeroEquips; ++j) {
			if (j == i) {

			}

			else {

				if (League[j][i].local < League[j][i].visitant) {
					Classificacio[j].punts += 3;
				}

				else if (League[j][i].local > League[j][i].visitant) {
					Classificacio[i].punts += 3;
				}

				else if (League[j][i].local == League[j][i].visitant) {
					Classificacio[i].punts += 1;
					Classificacio[j].punts += 1;
				}

				Classificacio[i].golsMarcats += League[j][i].local;
				Classificacio[j].golsMarcats += League[j][i].visitant;
				Classificacio[j].golsRebuts += League[j][i].local;
				Classificacio[i].golsRebuts += League[j][i].visitant;
			}

		}

	}
}

bool puntComparacio(classificacio& equip1, classificacio& equip2) {
	if (equip1.punts < equip2.punts) return false;
	else if (equip1.punts == equip2.punts) {
		int a1 = equip1.golsMarcats;
		int a2 = equip1.golsRebuts;
		int b1 = equip2.golsMarcats;
		int b2 = equip2.golsRebuts;
		if ((a1 - a2) > (b1 - b2)) return true;
		else if ((a1 - a2) < (b1 - b2)) return false;
		else {
			return equip1.equip < equip2.equip;
		}
	}
	return true;
}

void ordenarPosicions(Equips& Classificacio) {
	sort(Classificacio.begin(), Classificacio.end(), puntComparacio);
}

void imprimirResultats(Equips& Classificacio) {
	for (int i = 0; i < Classificacio.size(); ++i) {
		cout << Classificacio[i].equip << ' ' << Classificacio[i].punts << ' ' <<
			Classificacio[i].golsMarcats << ' ' << Classificacio[i].golsRebuts << endl;
	}
}

int main() {
	int numeroEquips;
	cin >> numeroEquips;

	Lliga League(numeroEquips, vector<partits>(numeroEquips));
	Equips Classificacio(numeroEquips);

	lecturaDades(League, numeroEquips);
	procesDades(League, numeroEquips, Classificacio);
	ordenarPosicions(Classificacio);
	imprimirResultats(Classificacio);
}