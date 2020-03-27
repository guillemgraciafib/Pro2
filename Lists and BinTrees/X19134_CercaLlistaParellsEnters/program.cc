#include "LlistaIOParInt.hh"

int main() {
    LlistaIOParInt ioList;
    list<ParInt> parList;

    ioList.LlegirLlistaParInt(parList);
    int n, suma, count;
    suma =  count = 0;
    cin >> n;

    for(list<ParInt>::const_iterator it = parList.begin(); it != parList.end(); ++it) {
        if(it->primer() == n) {
            ++count;
            suma +=  it->segon();
        }
    }

    cout << n << " " << count << " " << suma << endl;
}