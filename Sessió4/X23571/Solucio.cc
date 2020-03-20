#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
     int counter = 0;
     bool found = false;
     while ((!found) and (counter < nest)) {
          if (vest[counter].te_nota()) {
               if (vest[counter].consultar_nota() >= nota_b) {
                    return counter;
               }
          }
          ++counter; 
     }
     return counter;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat) {
     trobat = false;
     int posicio = cerca_dicot_per_dni(vest, 0, nest - 1, est.consultar_DNI());
     if ((posicio < nest) and (vest[posicio].consultar_DNI() == est.consultar_DNI())) {
          trobat = true;
     }
     if (!trobat) {
          if (est.te_nota() == false) ++primer_est_amb_nota;     
          vest[nest] = est;
          ++nest;
          ordenar();
     }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
   int posicioInicial = posicio_nota(nota_i);
   int posicioFinal = posicio_nota(nota_s);

   for (int i = posicioInicial; i <= posicioFinal; ++i) {
        vest[i].escriure();
   }
   if (vest[posicioFinal + 1].te_nota() and vest[posicioFinal + 1].consultar_nota() == nota_s) {
        vest[posicioFinal + 1].escriure();
   }

}
  