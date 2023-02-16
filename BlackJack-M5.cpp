// BlackJack-M5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

string croupierName = "Croupier";
int croupierPoints = 0;
string playerName;
int playerPoints = 0;
int giveCard;

string card[4][13] = { /*spades*/   { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" },
					   /*clubs*/    { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" },
					   /*hearts*/   { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" },
					   /*diamonds*/ { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" } } ;

int cardValue;
int randomNum;
int randomType;

bool win = false;
bool lose = false;
bool tie = false;

void dealCards(int& points, string name) {
	do {
		randomNum = rand() % 13;
		randomType = rand() % 4;
	} while (card[randomType][randomNum] == "used");

	if (randomNum == 0) {
		if (name != croupierName) {
			cout << "How many points do you want to get from the A, 1 or 11? ";

			do {
				cin >> cardValue;
				if (cardValue != 1 && cardValue != 11) {
					cout << "The value must be either 1 or 11. Try again: ";
				}
			} while (cardValue != 1 && cardValue != 11);

		}
		else {
			if ((11 + croupierPoints) > 21) {
				cardValue = 1;
			}
			else {
				cardValue = 11;
			}
		}
	}
	else {
		if (randomNum < 9 && randomNum > 0) {
			cardValue = randomNum + 1;
		}
		else {
			cardValue = 10;
		}
	}
	cout << name << " has received " << card[randomType][randomNum] << " of ";
	if (randomType == 1) {
		cout << "spades\n";
	}
	else if (randomType == 2) {
		cout << "clubs\n";
	}
	else if (randomType == 3) {
		cout << "hearts\n";
	}
	else {
		cout << "diamonds\n";
	}
	card[randomType][randomNum] = "used";
	points = points + cardValue;
}

void showPoints(string name, int points) {
	cout << name << " points: " << points << "\n";
}

void playerTurn() {
	do {
		cout << "Do you want another card?\n";
		cout << "YES [1] / NO [2]\n";
		cin >> giveCard;
		if (giveCard == 1) {
			dealCards(playerPoints, playerName);
		}
		showPoints(playerName, playerPoints);
	} while (giveCard == 1 && playerPoints < 21);
}

void croupierTurn() {
	while ((croupierPoints <= playerPoints) && (croupierPoints < 21)) {
		dealCards(croupierPoints, croupierName);
	}
}

void endMessage() {
	if (win == true) {
		cout << playerName << " has won the game.";
	}
	else if (lose == true) {
		cout << croupierName << " has won the game.";
	}
	else {
		cout << "It's a tie.";
	}
}

int main()
{
	srand(time(NULL));
	cout << "Enter your name: ";
	cin >> playerName;
	cout << "*The croupier starts shuffeling the deck of cards and deling the cards.*\n";
	while (!win && !lose && !tie) {
	//while ((win != true) && (lose != true) && (tie != true)) {
		dealCards(playerPoints, playerName);
		dealCards(playerPoints, playerName);
		dealCards(croupierPoints, croupierName);
		showPoints(playerName, playerPoints);
		showPoints(croupierName, croupierPoints);
		if (playerPoints == 21) {			
			croupierTurn();
			if (croupierPoints == playerPoints) {
				tie = true;
			}
			else if ((croupierPoints < playerPoints) || (croupierPoints > 21)) {
				win = true;
			}
			else {
				lose = true;
			}
		}
		else {
			playerTurn();
			if (playerPoints > 21) {
				lose = true;
			}
			else {
				croupierTurn();
				showPoints(croupierName, croupierPoints);

				if (croupierPoints == playerPoints) {
					tie = true;
				}
				else if ((croupierPoints < playerPoints) || (croupierPoints > 21)) {
					win = true;
				}
				else {
					lose = true;
				}
			}
		}
	}
	endMessage();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
