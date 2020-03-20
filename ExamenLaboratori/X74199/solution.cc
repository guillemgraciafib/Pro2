#include "Cjt_estudiants.hh"
   /* Pre: el par�metre impl�cit no est� ple */
   /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
   int x = est.consultar_DNI();
   int i = cerca_dicot(vest,0,nest-1,x);
   b = (i<nest) and (x== vest[i].consultar_DNI());

   if (not b) {
      for (int j=nest; j>i; --j) vest[j] = vest[j-1];
      vest[i] = est;
      ++nest;
      if (i <= pitjor_becat) ++pitjor_becat;

      if (est.te_nota()) {
         double estNota = est.consultar_nota();
         if (estNota >= min_nota_beca) {

            if (num_beques < max_beques){
               ++num_beques;
               if (pitjor_becat == -1) pitjor_becat = i;
               else if (vest[pitjor_becat].mes_prioritari(est)) pitjor_becat = i;
            }
            else if (num_beques == max_beques and est.mes_prioritari(vest[pitjor_becat])){
               int imm_millor = immediatament_millor(pitjor_becat);
               if (imm_millor >= 0) pitjor_becat = imm_millor;
            }
         }
      }      
   }
}


/* Operaci� immediatament_millor: la linia del cout no pinta res i haurieu de
   treure-la quan comenceu a implementar l'operaci�, per� permet fer
   lliuraments sense error de compilaci�, de forma que l'altra operaci� es
   podria avaluar manualment
*/
/* Pre: 0<=i<nest; vest[i] te nota */
/* Post: el resultat �s la posici� en vest[0..nest-1] de l'estudiant
   immediatament millor que vest[i], si n'hi ha; -1 en cas contrari */

int Cjt_estudiants::immediatament_millor(int i) const {
   int j = -1;
   
   for (int k = 0; k < nest and j == -1; ++k){
      if (vest[k].te_nota() and vest[k].mes_prioritari(vest[i])) j = k;
   }

  for (int k = j; k < nest; ++k){
      if (vest[k].te_nota() and vest[k].mes_prioritari(vest[i]) and vest[j].mes_prioritari(vest[k])) j = k;
   }
   return j;
}


