#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> recount;

    char code;
    string name;

    while(cin >> code >> name) {
        map<string, int>::iterator it = recount.find(name);
        if(code == 'a') {
            if(it == recount.end()) {
                recount.insert(make_pair(name, 1));
            }
            else {
                it->second++;
            }
        }
        else if(code == 'f') {
            if(it == recount.end()) {
                cout << 0 << endl;
            }
            else {
                cout << it->second << endl;
            }
        }
    }
}