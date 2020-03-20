#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  static const int MAX_NEST = 10; // nombre maxim d'elements del conjunt

  int max_beques, num_beques;
  
  double min_nota_beca;

  int pitjor_becat; // posicio de l'estudiant becat menys prioritari
		    // (o -1 si no n'hi ha cap)

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel dni dels estudiants i no cont� estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - 0 <= min_nota_beca <= Estudiant::nota_maxima()
     - 0 <= num_beques <= max_beques <= nest
     - num_beques = min(max_beques, nombre d'elements de vest[0..nest-1] amb nota >=min_nota_beca)  
     - 0 <= pitjor_becat < nest si i nomes si hi ha cap estudiant a vest[0..nest-1]
       amb nota >= min_nota_beca; en cas afirmatiu, v[pitjor_becat] es l'estudiant
       becat menys prioritari; en cas contrari, pitjor_becat=-1
  */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */

  // Operacio nova: 
   int immediatament_millor(int i) const;
  /* Pre: 0<=i<nest; vest[i] te nota */
  /* Post: el resultat �s la posici� en vest[0..nest-1] de l'estudiant
     immediatament millor que vest[i], si n'hi ha; -1 en cas contrari */ 

  
public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit amb un maxim de 0 beques
     i nota minima per tenir beca = Estudiant::nota_maxima() */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */


  //Consultores

  
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conte el parametre implicit */
  /* Post: el resultat es l'estudiant i-essim del parametre implicit
     en ordre creixent per DNI */

  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre maxim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */

  // Operacio nova:
  int estudiants_amb_beca() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants amb beca del p.i. */

  // Operacio nova: retorna l'estudiant amb mes possibilitat de perdre la beca
  Estudiant becat_menys_prioritari() const;
  /* Pre: el p.i. cont� com a minim un estudiant amb beca */
  /* Post: el resultat �s el becat amb menys prioritat del p.i. */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal est�ndar d'entrada un enter  (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants del
     par�metre impl�cit en ordre ascendent per DNI */
};

#endif

