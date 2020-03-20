#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
     b = false;
     int posicio = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
     if (vest[posicio].consultar_DNI() == est.consultar_DNI()) b = true;
     else {
          vest[nest] = est;
          nest++;
          ordenar_cjt_estudiants();
          if (est.te_nota()) {
               suma_notes += est.consultar_nota();
               nest_amb_nota++;
          }
     }    
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
     b = false;
     int posicio = cerca_dicot(vest, 0, nest - 1, dni);
     if (posicio < nest and vest[posicio].consultar_DNI() == dni) {
          b = true;
          if (vest[posicio].te_nota()) {
               suma_notes -= vest[posicio].consultar_nota();
               nest_amb_nota--;
          }
          nest--;
          for (int i = posicio; i < nest; ++i) {
               vest[i] = vest[i + 1];
          }
          
     }    
}