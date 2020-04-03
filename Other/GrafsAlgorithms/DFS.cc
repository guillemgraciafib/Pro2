#include "DFS.hh"

DFS::DFS() {

}

DFS::~DFS() {
}

bool PushSortida(vector <Vertex*> sortida, Vertex* v) {
    int size = sortida.size();

    for(int i = 0; i < size; ++i) {
        if(sortida[i]->GetID() == v->GetID()) return false;
    }
    sortida.push_back(v);
    return true;
}

vector<Vertex*> DFS::CalcularDFS(Graf* entrada, Vertex* inici) {
    stack<Vertex*> pila;
    vector <Vertex*> sortida;

    pila.push(inici);
    sortida.push_back(inici);
    int currentPos = 0;

    while(!pila.empty()) {
        Vertex* current = pila.top();
        if(PushSortida(sortida, current->GetAdjacentAt(currentPos))) {
            pila.push(current->GetAdjacentAt(currentPos));
            currentPos = 0;
            if(sortida.size() == entrada->GetOrdre()) {
                break;
            }
        }
        else {
            if(++currentPos >= current->GetGrau()) {
                currentPos = 0;
                pila.pop();
            }
        }
    }

    while(!pila.empty()) {
        if(pila.top != nullptr) {
            delete pila.top;
            pila.pop();
        }   
    }

    return sortida;
}