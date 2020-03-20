#include "Cjt_estudiants.hh"

// Traieu els comentaris (excepte els de les especificacions) i
// completeu les operacions

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
    if (est.te_nota()) {
      int nota = est.consultar_nota();
      if (nota < 5) {
        ++nombre_suspesos;
        if (nota >= 4) ++nombre_compensables;
      }

    }
    else {
      ++nombre_suspesos;
    }
  }
}

  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat del par�metre impl�cit */

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
  
     
  int i = cerca_dicot(vest,0,nest-1,dni); 
  b = (i<nest) and (dni == vest[i].consultar_DNI());
 

  if (b) {
    if (vest[i].te_nota()) {
      int nota = vest[i].consultar_nota();
      if (nota < 5) {
        --nombre_suspesos;
        if (nota >= 4) --nombre_compensables;
      }

    }
    else {
      --nombre_suspesos;
    }
    for (int j = i; j < nest - 1; ++j) vest[j] = vest[j + 1];
    --nest; 
    
  }
}