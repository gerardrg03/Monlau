#pragma once
#include <iostream>
using namespace std;

extern string mazmorra[39][8];
extern int atMazmorra[39][8];
extern string blank;
extern int ii, yy;

class Personaje {
protected:
	string nombre;
	int vida;
	int ataque;
	int posicionX;
	int posicionY;
	string cabeza;
	string torso;
	string piernas;
	bool alerta;

public:
	Personaje(string pNombre, int pVida, int pAtaque, int pPosicionX, int pPosicionY, string pCabeza, string pTorso, string pPiernas, bool pAlerta);

	string getNombre();
	int getVida();
	int getAtaque();
	int getPosicionX();
	int getPosicionY();
	string getCabeza();
	string getTorso();
	string getPiernas();
	bool getAlerta();

	void setNombre(string pNombre);
	void setVida(int pVida);
	void setAtaque(int pAtaque);
	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);
	void setCabeza(string pCabeza);
	void setTorso(string pTorso);
	void setPiernas(string pPiernas);
	void setAlerta(bool pAlerta);
	
	void modArr(int x, int y);
	void posicionArr();
	void moverExplorador();
	void recibirDaño();
	
};