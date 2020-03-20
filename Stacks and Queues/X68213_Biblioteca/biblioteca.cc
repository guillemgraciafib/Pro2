#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
int main() {
    int numeroPiles;
    cin >> numeroPiles;
    vector <stack<string>> Piles(numeroPiles);
    int aux;
    while (cin >> aux && aux != -4) {
        int pila;
        if (aux == -1) {
            string titol;
            cin >> titol >> pila;
            Piles[pila - 1].push(titol);
        }
 
        else if (aux == -2) {
            int eliminar;
            cin >> eliminar >> pila;
            for (int i = 0; i < eliminar; ++i) {
                Piles[pila - 1].pop();
            }
        }
        else if (aux == -3) {
            cin >> pila;
            stack <string> PilaAux(Piles[pila - 1]);
            cout << "Pila de la categoria " << pila << endl;
            int PilaAuxSize = PilaAux.size();
            for (int i = 0; i < PilaAuxSize; ++i) {
                cout << PilaAux.top() << endl;
                PilaAux.pop();
            }
               cout << endl;
        }
    }
}