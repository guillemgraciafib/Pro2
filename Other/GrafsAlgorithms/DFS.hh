#ifndef DFS_HH
#define DFS_HH
#include <stack>
#include "Graf.hh"
using namespace std;

class DFS {

public:
    DFS();
    ~DFS();

    vector<Vertex*> CalcularDFS(Graf*, Vertex*);
};

#endif