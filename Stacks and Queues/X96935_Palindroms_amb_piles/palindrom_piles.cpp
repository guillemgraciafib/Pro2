#include <iostream>
#include <stack>
using namespace std;

int main() {
    int size;
    cin >> size;
    stack <int> stck;
    int counter = 0;
    int aux;

    while (counter < size / 2) {
        cin >> aux;
        stck.push(aux);
        ++counter;
    }

    if (size % 2 != 0) {
        cin >> aux;
    }

    bool esPalindrom = true;
    while ((esPalindrom) && (counter >= 1)) {
        cin >> aux;
        int top = stck.top();
        if (top != aux) esPalindrom = false;
        else stck.pop();
        --counter;
    }

    if (esPalindrom or size < 0) cout << "SI" << endl;
    else cout << "NO" << endl;
}