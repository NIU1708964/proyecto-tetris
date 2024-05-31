#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "ClasesTEST.h"
#include <fstream>



#define COLOCAR_FIGURA 10 
#define ELIMINAR_1_FILA 100
#define ELIMINAR_2_FILA 150
#define ELIMINAR_3_FILA 175
#define ELIMINAR_4_FILA 200


#define PUJAR_NIVEL 1000
#define VELOCITAT_PRIMER_NIVEL 1.5
#define AUGMENT_VELOCITAT 0.75




using namespace std;

class Partida 
{
public:

    Partida() : m_mode(MODE_NORMAL), tiempo(0.0), puntuacio_actual(0), nivell_actual(1), velocitat_actual(VELOCITAT_PRIMER_NIVEL) {}              
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(int mode, double deltaTime);
    bool GetFinal() const { return final; } 
    void MostrarPuntuacio_Nivell(); 
    void LLegirFigures(const string& fitxerFigures);
    void LLegirMoviments(const string& fitxerMoviments);

private:

    int m_mode;
    double tiempo;
    Joc m_joc;
    int puntuacio_actual;
    int nivell_actual;
    double velocitat_actual;
    bool final;

    NodeMoviments* primeroM;
    NodeMoviments* Movimientos;

    NodeFigures* primeroF;
    NodeFigures* Figuras;

    void NivellActualitzacio(); 


  
};

#endif 
