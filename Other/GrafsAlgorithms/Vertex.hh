#ifndef VERTEX_HH
#define VERTEX_HH
#include <vector>
using namespace std;

class Vertex {
    friend class Graf;
    int id;
    int grau;

    vector<Vertex*> adjacents;

public:
    Vertex(int);
    ~Vertex();

    int GetID() {return id; };
    int GetGrau() { return grau; };
    int AddAdjacent(Vertex*);
    vector<Vertex*> GetAdjacents() { return adjacents; };
    Vertex* GetAdjacentAt(int);
};
#endif