#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "Personaje.h"
#include "EnemigoFinal.h"
using namespace std;

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
int ii = 39, yy = 8;
string mazmorra[39][8];
int atMazmorra[39][8];
string blank = "       ";
bool win, lose = false;


int main() {
	srand(time(NULL));
	//for (int k = 1; k < 255; k++){SetConsoleTextAttribute(hc, k);cout << k << " I want to be nice today!" << endl;}

	
	for (int i = 0; i < ii; i++) {
		for (int y = 0; y < yy; y++) {
			mazmorra[i][y] = blank;
			atMazmorra[i][y] = 0;
		}
	}

	atMazmorra[38][4] = -2;

	Personaje explorador("Explorador", 100, 12, 0, 3, "   O | ", " ()Y\\^ ", "  /^\\  ", false);
	Personaje enemigo1("Enemigo1", 25, 5, 1, rand() % 8, "  \\0/  ", "  /o\\  ", "   '   ", false);
	Personaje enemigo2("Enemigo2", 25, 5, 3, rand() % 8, "  \\0/  ", "  /o\\  ", "   '   ", false);
	Personaje enemigo3("Enemigo3", 25, 5, 5, rand() % 8, "  \\0/  ", "  /o\\  ", "   '   ", false);
	Personaje enemigo4("Enemigo4", 25, 5, 7, rand() % 8, "  \\0/  ", "  /o\\  ", "   '   ", false);
	Personaje enemigo5("Enemigo5", 25, 5, 9, rand() % 8, "  \\0/  ", "  /o\\  ", "   '   ", false);

	EnemigoFinal boss("Boss", 50, 15, 11, 4, " \\>O</ ", " // \\\\ ", " |\\_/| ", false, 20);
	//EnemigoFinal boss("Boss", 50, 12, 12, rand() % 13, " _\\(.- ", " _;oO  ", "  /(`- ", 20);

	explorador.posicionArr();
	enemigo1.posicionArr();
	enemigo2.posicionArr();
	enemigo3.posicionArr();
	enemigo4.posicionArr();
	enemigo5.posicionArr();
	boss.posicionArr();

	while (!win && !lose) {
		
		system("cls");
		cout << "\n";
		for (int i = (explorador.getPosicionX() - 2) * 3; i <= ((explorador.getPosicionX() + 2) * 3) + 2; i++) {
			cout << "                                          ";
			for (int y = explorador.getPosicionY() - 2; y <= explorador.getPosicionY() + 2; y++) {
				
				if ((i >= 0) && (i < ii) && (y >= 0) && (y < yy)) {
					if (atMazmorra[i][y] == 0){
						SetConsoleTextAttribute(hc, 96);
						cout << mazmorra[i][y];
						SetConsoleTextAttribute(hc, 0);
					}
					else if (atMazmorra[i][y] == -1) {
						SetConsoleTextAttribute(hc, 64);
						cout << mazmorra[i][y];
						SetConsoleTextAttribute(hc, 0);
					}
					else if (atMazmorra[i][y] == -2) {
						SetConsoleTextAttribute(hc, 240);
						cout << mazmorra[i][y];
						SetConsoleTextAttribute(hc, 0);
					}
					else {
						SetConsoleTextAttribute(hc, 100);
						cout << mazmorra[i][y];
						SetConsoleTextAttribute(hc, 0);
					}
				}
				else {
					SetConsoleTextAttribute(hc, 136);  
					cout << blank;
					SetConsoleTextAttribute(hc, 0);
				}
			}
			cout << "       " << "\n";
		}

		SetConsoleTextAttribute(hc, 4);
		cout << "                                          ";
		//cout << explorador.getPosicionX() << "  " << explorador.getPosicionY() << "  " << boss.getVida();
		cout << "Vida:";
		for (int i = 0; i < explorador.getVida(); i = i + 5) {
			if (i % 2 == 0) {
				cout << "<";
			}
			else {
				cout << "3 ";
			}
		}
		SetConsoleTextAttribute(hc, 0);
		for (int i = 0; i < ii; i++) {
			for (int y = 0; y < yy; y++) {
				if (atMazmorra[i][y] >= 0) {
					atMazmorra[i][y] = 0;
				}
			}
		}

		explorador.moverExplorador();
		enemigo1.modArr((explorador.getPosicionX()*3), explorador.getPosicionY());
		enemigo2.modArr((explorador.getPosicionX() * 3), explorador.getPosicionY());
		enemigo3.modArr((explorador.getPosicionX() * 3), explorador.getPosicionY());
		enemigo4.modArr((explorador.getPosicionX() * 3), explorador.getPosicionY());
		enemigo5.modArr((explorador.getPosicionX() * 3), explorador.getPosicionY());
		boss.modArr((explorador.getPosicionX() * 3), explorador.getPosicionY());

		explorador.recibirDaño();
		enemigo1.recibirDaño(); 
		enemigo2.recibirDaño(); 
		enemigo3.recibirDaño(); 
		enemigo4.recibirDaño();
		enemigo5.recibirDaño();
		boss.recibirDaño();
		if (boss.getVida() <= 20) {
			boss.setAtaque(boss.getAtaqueEspecial());
		}


		if (explorador.getVida() <= 0) {
			lose = true;
		}
		if (boss.getVida() <= 0 && explorador.getPosicionX() == 12 && explorador.getPosicionY() == 4) {
			win == true;
		}
	}
	cout << "                                              ";
	if(lose == true){
		SetConsoleTextAttribute(hc, 4);
		cout << "HAS MUERTO";
	}
	if (win == true) {
		SetConsoleTextAttribute(hc, 10);
		cout << "HAS GANADO";
	}
	
	return 0;
}