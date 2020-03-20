// Poseu aqui vostre nom, cognoms i grup de laboratori

#include "Cjt_estudiants.hh"
#include "solution.hh"
#include <algorithm>

void escriure_becats(const Cjt_estudiants& c) {
   int estudiantAmbBeca = c.estudiants_amb_beca();
   cout << estudiantAmbBeca << endl;

   if (estudiantAmbBeca == 1) {
      Estudiant ultimBecat = c.becat_menys_prioritari();
      ultimBecat.escriure();
   }

   else if (estudiantAmbBeca > 1) {
      int counter = 0;
      Estudiant ultimBecat = c.becat_menys_prioritari();

      while (estudiantAmbBeca > 0) {
         Estudiant iessim = c.consultar_iessim(counter + 1);
         if (iessim.te_nota()){
            if (iessim.consultar_nota() > ultimBecat.consultar_nota()) {
               cout << iessim.consultar_DNI() << ' ' << iessim.consultar_nota() << endl;
               --estudiantAmbBeca;
            } 
            else if ((iessim.consultar_nota() == ultimBecat.consultar_nota()) && (iessim.consultar_DNI() >= ultimBecat.consultar_DNI())) {
               cout << iessim.consultar_DNI() << ' ' << iessim.consultar_nota() << endl;
               --estudiantAmbBeca;
            }
         }
         ++counter;
      }
   }
}


   /* Pre: cert */
   /* Post: s'han escrit pel canal est�ndar de sortida els estudiants
     de c amb beca en ordre ascendent per DNI */