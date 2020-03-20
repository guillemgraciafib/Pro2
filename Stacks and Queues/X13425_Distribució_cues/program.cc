#include "CuaIOParInt.hh"
#include <vector>
 
void LlegeixDistribueix(vector<queue<ParInt>>& cua, CuaIOParInt& cuaIO) {
    vector<int> counter(cua.size(), 0);
    queue<ParInt> temp;
    cuaIO.llegirCuaParInt(temp);
 
    while (!temp.empty()) {
        int currentQueue = counter[1] < counter[0]; //Si, esto es legal y sirve para ahorrar ifs
 
        counter[currentQueue] += temp.front().segon();
        cua[currentQueue].push(temp.front());
        temp.pop();
    }
}
 
void EscriuCues(const vector<queue<ParInt>>& cua, CuaIOParInt& cuaIO) {
    for (int i = 0; i < cua.size(); ++i) {
        cuaIO.escriureCuaParInt(cua[i]);
        cout << endl;
    }
}
 
int main() {
    vector<queue<ParInt>> cua(2);
    CuaIOParInt cuaIO;
 
    LlegeixDistribueix(cua, cuaIO);
    EscriuCues(cua, cuaIO);
}