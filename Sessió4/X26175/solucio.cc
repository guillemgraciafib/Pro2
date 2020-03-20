#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
     b = false;
     int posicio = cerca_dicot(vest, 0, nest, est.consultar_DNI());
     if ((posicio < nest) and (vest[posicio].consultar_DNI() == est.consultar_DNI())) {
          b  = true;
     }

     if (!b) {
          vest[nest] = est;
          ++nest;
          ordenar();
          if (est.te_nota()) {
               incrementar_interval(est.consultar_nota());
          }
     }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
     b = false;
     int posicio = cerca_dicot(vest, 0, nest - 1, dni);
     if (posicio < nest and vest[posicio].consultar_DNI() == dni) {
          b = true;
          if (vest[posicio].te_nota()) {
               decrementar_interval(vest[posicio].consultar_nota());
          }
          
          for (int i = posicio; i < nest; ++i) {
               vest[i] = vest[i + 1];
          }
          --nest;
     }    
}