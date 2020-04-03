#include "Graf.hh"
#include "DFS.hh"
#include <iostream>
using namespace std;

void AfegirVertex (int i, Graf* ptr_g) {
    Vertex* v = new Vertex(0);
    ptr_g->AddVertex(v);
}

void PrintFormat () {
    cout << "Format: v0, v1, v2, ... (enters), vk, -1"  << endl;
}

void GetInput (Graf* g) {
    int quantitat = -1;
    while(quantitat < 0) {
        cout << "> Introdueix quants vertexs te el teu graf: ";
        cin >> quantitat;
        if(quantitat < 0) {
            cout << "ERROR: S'ha d'introduir un valor positiu o 0" << endl;
        }
        else {
            cout << "S'ha creat un graf d'ordre " << quantitat << " correctament." << endl;
        }
    }
    for (int i = 0; i < quantitat; ++i) {
        AfegirVertex(i, g);
    }
    cout << "Afegeix la llista d'adjacencies de cada vertex:" << endl;
    PrintFormat();

    for (int i = 0; i < quantitat; ++i) {
        cout << "> Adjacents al vertex " << i << ": ";
        int current;
        do {
            cin >> current;
            if(current > 0 && current < quantitat) {
                g->GetVertexAt(i)->AddAdjacent(g->GetVertexAt(current));
            }
            else if(current >= quantitat) {
                cout << "ERROR: Has intentat afegir un vertex inexistent. " << endl;
            }
            else if(current < -1) {
                cout << "ERROR de format. " << endl;
                PrintFormat();
            }
        } while (current != -1);
    }
}

void PrintMenu () {
    cout << "***************************************************" << endl;
    cout << "*  1 = DFS | 2 = BFS | 3 = Llista Adj | 4 = Exit  *" << endl;
    cout << "***************************************************" << endl;
    cout << "> Accio a realitzar:  ";
}

void PrintConjuntVertex (vector<Vertex*> v) {
    int size = v.size();
    for(int i = 0; i < size; ++i) {
        cout << v[i]->GetID() << " ";
    }
    cout << endl;
}

int main () {
    Graf* ptr_g = new Graf();
    GetInput(ptr_g);
    
    enum Action {Null, act_DFS, act_BFS, act_LlistaAdj, act_Exit};
    int currentAction;

    while (currentAction != act_Exit) {
        PrintMenu();
        cin >> currentAction;

        switch (currentAction) {
            case (act_DFS):
                int currentVertex;
                DFS* dfs = new DFS();
                cout << " Introdueix a quin vertex vols fer el DFS: ";
                cin >> currentVertex;
                cout << "Resultat DFS per al vertex " << currentVertex << ": " << endl;
                PrintConjuntVertex(dfs->CalcularDFS(ptr_g, ptr_g->GetVertexAt(currentVertex)));
                delete dfs;
                break;
            case (act_BFS):
                // int currentVertex;
                // BFS bfs;
                // cout << " Introdueix a quin vertex vols fer el BFS: ";
                // cin >> currentVertex;
                // cout << "Resultat BFS per al vertex " << currentVertex << ": " << endl;
                // PrintConjuntVertex(bfs.CalcularBFS(ptr_g, ptr_g->GetVertexAt(currentVertex)));
                break;
            case (act_LlistaAdj):
                break;
            case (act_Exit):
                cout << "ADEU! " << endl;
                break;
            default:
                cout << "ERROR: Opcio inexistent." << endl;
                break;
        }
    }
}