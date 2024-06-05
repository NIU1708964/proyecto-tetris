#include "Tetris.h"
#include <fstream>
#include <iostream>

using namespace std;

Tetris::Tetris(const string& fitxerP)
{
	ifstream fitxer;
	fitxer.open(fitxerP);
	
	if (fitxer.is_open())
	{
		Puntuacio p;
		fitxer >> p.nom >> p.punts;
		
		while (!fitxer.eof())
		{
			m_puntuacions.push_back(p); //coloca p en la ultima posicion
			fitxer >> p.nom >> p.punts;
		}
		fitxer.close();
	}
}

void Tetris::mostraMenu()
{
	cout << endl;

	cout << "MENU (ESCOLLEIX UNA OPCIO)" << endl;
	cout << "--------------------------" << endl;
	cout << "1- Jugar en mode normal" << endl;
	cout << "2- Jugar en mode test" << endl;
	cout << "3- Taula de puntuacions" << endl;
	cout << "4- Sortir a l'escriptori" << endl;
}

void Tetris::mostraPuntuacions()
{
	list<Puntuacio>::iterator i = m_puntuacions.begin();
	cout << "TAULA DE PUNTUACIONS" << endl; 
	cout << "====================" << endl;
	cout << endl;

	int cont = 1;
	while (i != m_puntuacions.end())
	{
		cout << cont << " - " << i->nom << " " << i->punts << endl;
		i++;
		cont++;
	}
	cout << endl;
}

void Tetris::actualitzaPuntuacions(const string& nom, int punts)
{
	Puntuacio p;
	list<Puntuacio>::iterator i;

	p.nom = nom;
	p.punts = punts;

	i = comparaPuntuacions(punts);
	m_puntuacions.insert(i, p); //inserta p a la posicion i
}

list<Puntuacio>::iterator Tetris::comparaPuntuacions(int punts)
{
	list<Puntuacio>::iterator i = m_puntuacions.begin();
	
	bool trobat = false;
	while (i != m_puntuacions.end() && !trobat)
	{
		if (punts > i->punts) //colocar a punts una vez encontremos un valor menor
		{
			trobat = true;
		}
		else
		{
			i++;
		}
	}

	return i;
}

void Tetris::guardaPuntuacions(const string& fitxerP)
{
	ofstream fitxer;
	fitxer.open(fitxerP);

	list<Puntuacio>::iterator i = m_puntuacions.begin();
	
	if (fitxer.is_open())
	{
		while (i != m_puntuacions.end())
		{
			fitxer << i->nom << " " << i->punts;
			fitxer << endl;
			i++;
		}
		fitxer.close();
	}
}

int Tetris::juga(Screen& pantalla, int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{

	pantalla.show();

	Partida partida;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

	double deltaTime = 0;
	bool partidaFinal = false, escape = false;

	partida.inicialitza(mode, "./data/Games/partida.txt", "./data/Games/figures.txt", "./data/Games/moviments.txt");


	do
	{	
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		pantalla.processEvents();

		partida.actualitza(deltaTime);
		partida.MostrarPuntuacio_Nivell();
		
		pantalla.update();

		if (partida.GetFinal())
		{
			partidaFinal = true;
			SDL_Delay(3000);
		}
		if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			escape = true;
		}

	} while (!escape && !partidaFinal); 

	int punts = partida.getPunts();

	return punts;
}