#include  "Vertex.hh"

Vertex::Vertex(int _id) {
    this->id = _id;
    this->grau = 0;
}

Vertex::~Vertex() {
    //Hay que eliminar los punteros si es que existen (quizas ya se ha eliminado)
    //y hay que comprobar porque si intentamos borrar uno ya borrado nos va a petar.
    for(int i = 0; i < adjacents.size(); ++i) {
        if(adjacents[i] != nullptr)
            delete adjacents[i];
    }
}

int Vertex::AddAdjacent(Vertex* v) {
    adjacents.push_back(v);
    return ++grau;
}

Vertex* Vertex::GetAdjacentAt(int i) {
    if(i >= 0 && i < grau) {
        return adjacents[i];
    }
    else return adjacents[0];
}