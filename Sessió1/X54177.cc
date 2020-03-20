#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
        int counter = 0;
        int c;
        while ((cin >> c) and (c != x)) {
            counter += c;
        }
        string a;
        getline(cin, a);


        cout << "La suma de la secuencia " << i << " es " << counter << endl;
    }
}