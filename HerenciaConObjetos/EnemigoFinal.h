#pragma once
#include <iostream>
#include "Personaje.h"
using namespace std;

extern string mazmorra[39][8];
extern int atMazmorra[39][8];
extern string blank;
extern int ii, yy;

class EnemigoFinal : public Personaje {
private:
	int ataqueEspecial;

public:
	EnemigoFinal(string pNombre, int pVida, int pAtaque, int pPosicionX, int pPosicionY, string pCabeza, string pTorso, string pPiernas, bool pAlerta, int pAtaqueEspecial);

	int getAtaqueEspecial();

	void setAtaqueEspecial(int pAtaqueEspecial);


};
