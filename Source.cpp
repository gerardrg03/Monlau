// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP1 = 100;
string enemyName1 = "Francisco";
bool enemyIsAlive1 = true;
int enemyDamage1;

//Atributos del enemigo 2
int enemyHP2 = 150;
string enemyName2 = "Adolfo";
bool enemyIsAlive2 = true;
int enemyDamage2;

//Atributos del heroe
int heroHP = 200;
int heroDamage;
string heroName;
bool heroIsAlive = true;

//Atributos del juego
int enemyChoosed = 0;
int magicPoints = 2;
int sopapoValue = 10;
int espadazoValue = 30;
int magicValue = 50;

void gameStart() {
    cout << "El enemigo " << enemyName1 << " ha aparecido\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}

bool checkEnemyAlive(bool& alive, int& hp, string name) {
    if (hp <= 0) {
        hp = 0;
        alive = false;
        cout << name << " ha sido derrotado.";
    }
    else {
        cout << name << " no ha sido derrotado.";
    }
}

int chooseEnemy() {
    int enemyChoose = 0;
    while (enemyChoose != 1 && enemyChoose != 2) {
        cout << "A que enemigo quieres atacar? \n";
        if (enemyIsAlive1) {
            cout << "1.- " << enemyName1 << "\n";
        }
        if (enemyIsAlive2) {
            cout << "2.- " << enemyName2 << "\n";
        }
        cin >> enemyChoose;
        if (enemyChoose <= 0 || enemyChoose > 2) {
            cout << "La opcion elegida no es correcta. Por favor, elige una opcion valida. \n";
        }
        if (!enemyIsAlive1 && enemyChoose == 1) {
            cout << "El enemigo " << enemyName1 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo." " \n";
            enemyChoose = 0;
        }
        if (!enemyIsAlive2 && enemyChoose == 2) {
            cout << "El enemigo " << enemyName2 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo." " \n";
            enemyChoose = 0;
        }
    }
    return enemyChoose;
}


int chooseAttack() {
    int attackChoose = 0;
    while (attackChoose != 1 && attackChoose != 2 && attackChoose != 3) {
        cout << "Que ataque quieres usar? \n";
        cout << "1.- Espadazo \n";
        cout << "2.- Sopapo \n";
        if (magicPoints > 0) {
            cout << "3.- Magia\n";
        }
        cin >> attackChoose;
        if (attackChoose <= 0 || attackChoose > 3) {
            cout << "El ataque seleccionado no es correcto. Por favor, elige una opcion valida. \n";
        }
        if (attackChoose == 3) {
            if (magicPoints > 0) {
                magicPoints--;
            }
            else {
                attackChoose = 0;
                cout << "No te queda magia. Por favor selecciona un ataque que puedas usar. \n";
            }
        }
    }
    if (attackChoose == 1) {
        return espadazoValue;
    }
    else if (attackChoose == 2) {
        return sopapoValue;
    }
    else {
        return magicValue;
    }
}

int heroAttack(int heroDamage, string enemyName, int & enemyHP) {
    cout << "Atacas al enemigo " << enemyName << " y le haces un daño de " << heroDamage << " \n";
    enemyHP = enemyHP - heroDamage;
    return enemyHP;
}

void enemyAttack(int & enemyDamage, string enemyName) {
    enemyDamage = 30 + rand() % 20;
    heroHP = heroHP - enemyDamage;
    if (heroHP > 0) {
        cout << "El enemigo " << enemyName << " te ha atacado y te quedan " << heroHP << " puntos de vida.\n";
    }
    else {
        cout << "El enemigo " << enemyName << " te ha atacado y te ha matado. El mundo esta condenado.\n";
        heroIsAlive = false;
    }
}

int main()
{
    gameStart();
    while (heroIsAlive && (enemyIsAlive1 || enemyIsAlive2)) {
        //ELEGIMOS ENEMIGO AL QUE ATACAR
        enemyChoosed = chooseEnemy();
        //ELEGIMOS ATAQUE Y CAPTURAMOS EL VALOR DEL DANYO QUE HAREMOS
        heroDamage = chooseAttack();

        if (enemyChoosed == 1) {
            //ATACAMOS AL ENEMIGO 1
            enemyHP1 = heroAttack(heroDamage, enemyName1, enemyHP1);
            enemyIsAlive1 = checkAlive(enemyIsAlive1, enemyHP1, enemyName1);
        }
        else {
            //ATACAMOS AL ENEMIGO 2
            enemyHP2 = heroAttack(heroDamage, enemyName2, enemyHP2);
            enemyIsAlive2 = checkAlive(enemyIsAlive2, enemyHP2, enemyName2);
        }
        //ATACA EL ENEMIGO 1 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive1 && heroIsAlive) {
            enemyAttack(enemyDamage1, enemyName1);
        }
        //ATACA EL ENEMIGO 2 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive2 && heroIsAlive) {
            enemyAttack(enemyDamge2, enemyName2);
        }
    }
}