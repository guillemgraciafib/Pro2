#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <char> stck;
    bool correcte = true;
    char c;
    while ((cin >> c) && (c != '.') && (correcte)) {
        if (c == ')') {
            if ((!stck.empty()) and stck.top() == '(') stck.pop();
            else correcte = false;
        }

        else if (c == ']') {
            if ((!stck.empty()) and stck.top() == '[') stck.pop();
            else correcte = false;
        }

        else stck.push(c);
    }

    if (stck.empty() and correcte) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}