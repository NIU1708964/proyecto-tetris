#ifndef TETRIS_H
#define TETRIS_H
#include <list>
#include "Partida.h"

typedef struct
{
	string nom;
	int punts;
}Puntuacio;

class Tetris
{
public:
	Tetris(const string& fitxerP);

	int juga(Screen& pantalla, int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	void mostraPuntuacions();
	void mostraMenu();
	void actualitzaPuntuacions(const string& nom, int punts);
	void guardaPuntuacions(const string& fitxerP);
	list<Puntuacio>::iterator comparaPuntuacions(int punts);

private:
	Partida m_joc;
	list<Puntuacio> m_puntuacions;
};

#endif 