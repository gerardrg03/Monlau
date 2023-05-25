#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Personaje.h"
using namespace std;

Personaje::Personaje(string pNombre, int pVida, int pAtaque, int pPosicionX, int pPosicionY, string pCabeza, string pTorso, string pPiernas, bool pAlerta) {
	nombre = pNombre;
	vida = pVida;
	ataque = pAtaque;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
	cabeza = pCabeza;
	torso = pTorso;
	piernas = pPiernas;
	alerta = pAlerta;
}


string Personaje::getNombre() {
	return nombre;
}
int Personaje::getVida(){
	return vida;
}
int Personaje::getAtaque(){
	return ataque;
}
int Personaje::getPosicionX(){
	return posicionX;
}
int Personaje::getPosicionY(){
	return posicionY;
}
string Personaje::getCabeza() {
	return cabeza;
}
string Personaje::getTorso() {
	return torso;
}
string Personaje::getPiernas() {
	return piernas;
}
bool Personaje::getAlerta() {
	return alerta;
}

void Personaje::setNombre(string pNombre) {
	nombre = pNombre;
}
void Personaje::setVida(int pVida) {
	vida = pVida;
}
void Personaje::setAtaque(int pAtaque) {
	ataque = pAtaque;
}
void Personaje::setPosicionX(int pPosicionX) {
	posicionX = pPosicionX;
}
void Personaje::setPosicionY(int pPosicionY) {
	posicionY = pPosicionY;
}
void Personaje::setCabeza(string pCabeza) {
	cabeza = pCabeza;
}
void Personaje::setTorso(string pTorso) {
	torso = pTorso;
}
void Personaje::setPiernas(string pPiernas) {
	piernas = pPiernas;
}
void Personaje::setAlerta(bool pAlerta) {
	alerta = pAlerta;
}

void Personaje::modArr(int x, int y) {
	if (getVida() > 0) {
		if (getAlerta() == true) {
			if (mazmorra[((getPosicionX() - 1) * 3)][getPosicionY()] == mazmorra[x][y]) {
				atMazmorra[x][y] = getAtaque();
				atMazmorra[x+1][y] = getAtaque();
				atMazmorra[x+2][y] = getAtaque();
			}
			else if (mazmorra[((getPosicionX() + 1) * 3)][getPosicionY()] == mazmorra[x][y]) {
				atMazmorra[x][y] = getAtaque();
				atMazmorra[x + 1][y] = getAtaque();
				atMazmorra[x + 2][y] = getAtaque();
			}
			else if (mazmorra[(getPosicionX() * 3)][(getPosicionY() + 1)] == mazmorra[x][y]){
				atMazmorra[x][y] = getAtaque();
				atMazmorra[x + 1][y] = getAtaque();
				atMazmorra[x + 2][y] = getAtaque();
			}
			else if (mazmorra[(getPosicionX() * 3)][(getPosicionY() - 1)] == mazmorra[x][y]) {
				atMazmorra[x][y] = getAtaque();
				atMazmorra[x + 1][y] = getAtaque();
				atMazmorra[x + 2][y] = getAtaque();
			}
		}
	}
	else {
		atMazmorra[getPosicionX() * 3][getPosicionY()] = -1;
		atMazmorra[(getPosicionX() * 3) + 1][getPosicionY()] = -1;
		atMazmorra[(getPosicionX() * 3) + 2][getPosicionY()] = -1;
	}

}
void Personaje::posicionArr() {
	mazmorra[(getPosicionX()*3)][getPosicionY()] = getCabeza();
	mazmorra[(getPosicionX()*3)+1][getPosicionY()] = getTorso();
	mazmorra[(getPosicionX()*3)+2][getPosicionY()] = getPiernas();
}
void Personaje::moverExplorador() {
	for (int i = 0; i < ii; i++) {
		for (int y = 0; y < yy; y++) {
			if (mazmorra[i][y] == getCabeza() || mazmorra[i][y] == getTorso() || mazmorra[i][y] == getPiernas()) {
				mazmorra[i][y] = blank;
			}
		}
	}
	

	switch (_getch()) {
	case 119: case 87://at arriba
		if (mazmorra[((getPosicionX() - 1) * 3)][getPosicionY()] != blank) {
			atMazmorra[((getPosicionX() - 1) * 3)][getPosicionY()] = getAtaque();
			atMazmorra[((getPosicionX() - 1) * 3) + 1][getPosicionY()] = getAtaque();
			atMazmorra[((getPosicionX() - 1) * 3) + 2][getPosicionY()] = getAtaque();
		}
		break;
	case 115: case 83://at abajo
		if (mazmorra[((getPosicionX() + 1) * 3)][getPosicionY()] != blank) {
			atMazmorra[((getPosicionX() + 1) * 3)][getPosicionY()] = getAtaque(); 
			atMazmorra[((getPosicionX() + 1) * 3) + 1][getPosicionY()] = getAtaque();
			atMazmorra[((getPosicionX() + 1) * 3) + 2][getPosicionY()] = getAtaque();
		}
		break;
	case 100: case 68://at derecha
		if (mazmorra[(getPosicionX() * 3)][(getPosicionY() + 1)] != blank) {
			atMazmorra[(getPosicionX() * 3)][(getPosicionY() + 1)] = getAtaque(); 
			atMazmorra[(getPosicionX() * 3) + 1][(getPosicionY() + 1)] = getAtaque();
			atMazmorra[(getPosicionX() * 3) + 2][(getPosicionY() + 1)] = getAtaque();
		}
		break;
	case 97: case 65://at izquierda
		if (mazmorra[(getPosicionX() * 3)][(getPosicionY() - 1)] != blank) {
			atMazmorra[(getPosicionX() * 3)][(getPosicionY() - 1)] = getAtaque(); 
			atMazmorra[(getPosicionX() * 3) + 1][(getPosicionY() - 1)] = getAtaque();
			atMazmorra[(getPosicionX() * 3) + 2][(getPosicionY() - 1)] = getAtaque();
		}
		break;
	case 72://arriba
		if (mazmorra[((getPosicionX() - 1) * 3)][getPosicionY()] == blank && (getPosicionX() - 1) >= 0 && getAlerta() == false) {
			setPosicionX(getPosicionX() - 1);
		}
		break;
	case 80://abajo
		if (mazmorra[((getPosicionX() + 1) * 3)][getPosicionY()] == blank && (getPosicionX() + 1) < ii && getAlerta() == false) {
			setPosicionX(getPosicionX() + 1);
		}
		break;
	case 77://derecha
		if (mazmorra[(getPosicionX() * 3)][(getPosicionY() + 1)] == blank && (getPosicionY() + 1) < yy && getAlerta() == false) {
			setPosicionY(getPosicionY() + 1);
		}
		break;
	case 75://izquierda
		if (mazmorra[(getPosicionX() * 3)][(getPosicionY() - 1)] == blank && (getPosicionY() - 1) >= 0 && getAlerta() == false) {
			setPosicionY(getPosicionY() - 1);
		}
		break;
	default:
		setPosicionX(getPosicionX()); 
		break;
	}

	mazmorra[(getPosicionX() * 3)][getPosicionY()] = getCabeza();
	mazmorra[(getPosicionX() * 3) + 1][getPosicionY()] = getTorso();
	mazmorra[(getPosicionX() * 3) + 2][getPosicionY()] = getPiernas();

	/*int k;
	k = _getch();
	switch (k)
	{
	default:
		cout << k;
		break;
	}
	*/
	
}
void Personaje::recibirDaño() {
	if (atMazmorra[getPosicionX() * 3][getPosicionY()] > 0) {
		setVida(getVida() - atMazmorra[getPosicionX() * 3][getPosicionY()]);
		setAlerta(true);
	}
	else {
		setAlerta(false);
	}
}
