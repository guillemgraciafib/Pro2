class Estudiant {
    // Tipus de mòdul: dades
    // Descripció del tipus: conté el DNI d'un estudiant,
    // que és un enter positiu, i pot tenir nota, que seria un double.
    // Les notes vàlides són les de l'interval 0..nota_maxima()

    private:

    public: // Totes les operacions tenen un cost temporal constant
    //Constructores i destructores
    
    Estudiant();
    /* Pre: cert */
    /* Post: el resultat és un estudiant amb DNI = 0 i sense nota */
    
    Estudiant(int dni);
    /* Pre: dni >= 0 */
    /* Post: el resultat és un estudiant amb DNI = dni i sense nota */
    // Destructora: esborra automàticament els objectes locals en sortir
    // d'un àmbit de visibilitat
    
    ~Estudiant();

    //Modificadores
    void afegir_nota(double nota);
    /* Pre: el paràmetre implícit no té nota, 0 <= "nota" <= nota_maxima() */
    /* Post: la nota del paràmetre implícit passa a ser "nota" */

    void modificar_nota(double nota);
    /* Pre: el paràmetre implícit té nota, 0 <= "nota" <= nota_maxima() */
    /* Post: la nota del paràmetre implícit passa a ser "nota" */


    //Consultores
    int consultar_DNI() const;
    /* Pre: cert */
    /* Post: el resultat és el DNI del paràmetre implícit */
    
    double consultar_nota() const;
    /* Pre: el paràmetre implícit té nota */
    /* Post: el resultat és la nota del paràmetre implícit */
    
    static double nota_maxima();
    /* Pre: cert */
    /* Post: el resultat és la nota màxima dels elements de la classe */
    
    bool te_nota() const;
    /* Pre: cert */
    /* Post: el resultat indica si el paràmetre implícit té nota o no */
    // Lectura i escriptura
    
    void llegir();
    /* Pre: hi ha preparats al canal estandar d'entrada un enter no negatiu seguit d'un
    double */
    /* Post: s'ha llegit l'enter i el double pel canal estàndard d'entrada; el paràmetre
    implícit passa a tenir l'enter com a DNI i el double com a nota; si el double no pertany
    a l'interval [0..nota_maxima()], el p.i. es queda sense nota */
    
    void escriure() const;
    /* Pre: cert */
    /* Post: s'han escrit el DNI i la nota del paràmetre implícit
    al canal estàndard de sortida; si no té nota escriu "NP" */
};