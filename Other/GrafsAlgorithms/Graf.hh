#ifndef GRAF_HH
#define GRAF_HH
#include "Vertex.hh"

using namespace std;

class Graf {
    vector<Vertex*> vertex;
    int mida;
    int ordre;

public:
    Graf();
    ~Graf();

    int GetMida() { return mida; };
    int GetOrdre() { return ordre;  };

    vector<Vertex*> GetAllVertex() {return vertex; };
    Vertex* GetVertexAt(int);

    int AddVertex(Vertex*);

    vector<Vertex> DeleteVertexAt(int);
    vector<Vertex> Reset();
};

#endif