#include "LlistaIOEstudiant.hh"
using namespace std;

int main(){
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);
    int n;
    cin >> n;
    int counter = 0;
    for(list<Estudiant>::const_iterator it = l.begin(); it != l.end(); ++it){
        if(it->consultar_DNI() == n) ++counter;
    }
    cout << n << " " << counter << endl;
}