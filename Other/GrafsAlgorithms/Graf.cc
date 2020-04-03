#include "Graf.hh"

Graf::Graf() {
    mida = 0;
    ordre = 0;
}

Graf::~Graf() {
    //Hay que eliminar los punteros si es que existen (quizas ya se ha eliminado)
    //y hay que comprobar porque si intentamos borrar uno ya borrado nos va a petar.
    for(int i = 0; i < vertex.size(); ++i) {
        if(vertex[i] != nullptr)
            delete vertex[i];
    }
}

Vertex* Graf::GetVertexAt(int i) {
    if(i >= 0 && i < ordre) {
        return vertex[i];
    }
    else return vertex[0];
}

int Graf::AddVertex(Vertex* v) {
    v->id = ordre++;
    vertex.push_back(v);
    mida += v->GetGrau();
    return ordre;
}