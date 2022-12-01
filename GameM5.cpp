#include<stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

string directAtack;

//Atributos del enemigo 1
string enemyName1 = "Dark";
int enemyHealth1 = 1000;
bool enemyIsAlive1 = true;

//Atributos del enemigo 2
string enemyName2 = "Light";
int enemyHealth2 = 1500;
bool enemyIsAlive2 = true;

//Atributos del heroe
string heroName;
int heroDamage1;
int heroHealth1 = 1900;
int	numAtack1 = 5;
int numAtack2 = 5;
bool heroIsAlive1 = true;
string typeAtack;


void cancion() {
	Beep(220, 300);

	Beep(294, 300);

	Beep(294, 300);

	Beep(370, 300);

	Beep(494, 300);

	Beep(370, 300);

	Beep(440, 800);

	/* */

	Beep(440, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(370, 300);

	Beep(392, 300);

	Beep(370, 300);

	Beep(330, 800);

	/* */

	Beep(247, 300);

	Beep(330, 300);

	Beep(330, 300);

	Beep(370, 300);

	Beep(555, 300);

	Beep(555, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(392, 800);

	Beep(392, 300);

	Beep(370, 300);

	Beep(247, 800);

	Beep(278, 300);

	Beep(294, 300);

	Beep(330, 2600);

	/* */

	Beep(220, 300);

	Beep(294, 300);

	Beep(294, 300);

	Beep(370, 300);

	Beep(494, 300);

	Beep(370, 300);

	Beep(440, 800);

	/* */

	Beep(440, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(370, 300);

	Beep(392, 300);

	Beep(370, 300);

	Beep(330, 800);

	/* */

	Beep(247, 300);

	Beep(330, 300);

	Beep(330, 300);

	Beep(370, 300);

	Beep(555, 300);

	Beep(555, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(392, 800);

	Beep(392, 300);

	Beep(370, 300);

	Beep(278, 600);

	Beep(330, 600);

	Beep(294, 2600);

	/*Reff : */

	Beep(494, 300);

	Beep(494, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(392, 200);

	Beep(440, 200);

	Beep(494, 200);

	Beep(440, 800);

	Beep(330, 300);

	Beep(370, 300);

	Beep(416, 300);

	Beep(330, 300);

	Beep(440, 2000);

	/* */

	Beep(494, 800);

	Beep(440, 800);

	Beep(392, 1600);

	/* */

	Beep(555, 300);

	Beep(555, 300);

	Beep(555, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(392, 1400);

	/* */

	Beep(440, 300);

	Beep(494, 300);

	Beep(370, 1100);

	Beep(330, 300);

	Beep(294, 1800);

	/* */

	Beep(494, 800);

	Beep(440, 800);

	Beep(392, 1600);

	/* */

	Beep(555, 300);

	Beep(555, 300);

	Beep(555, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(494, 300);

	Beep(440, 300);

	Beep(392, 1400);

	/* */

	Beep(440, 300);

	Beep(494, 300);

	Beep(370, 1100);

	Beep(330, 300);

	Beep(294, 1800);


	cin.get();


}

void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void startGame() {
	std::cout << "Los enemigos " << enemyName1 << " y " << enemyName2 << " acaban de aparecer\n";
	cout << "\n" << enemyName1 << " tiene " << enemyHealth1 << " de vida.\n";
	cout << "\n" << enemyName2 << " tiene " << enemyHealth2 << " de vida.\n";
	cout << "\nPonle un nombre al hereo que va a luchar conra los enemigos => ";
	cin >> heroName;
	cout << "\nEl nombre del heroe es: " << heroName << "\n";
	delay(4);
	system("cls");
}

void atackTypes() {
	cout << "\nEl ataque ira dirigido a " << enemyName1 << " que ataque quieres usar?\n";
	cout << "\n[1] Ataque Rayo\n";
	cout << "\n[2] Ataque Agua\n";
	cout << "\n[3] Ataque Fuego\n";
	cin >> typeAtack;
}

void chooseAtack() {
	srand((unsigned)time(NULL));
	cout << "\nEl heroe " << heroName << " va a realizar su ataque.\n";
	cout << "\nA que enemigo quieres atacar? Light (l) - Dark (d) ";
	cin >> directAtack;
}

void limitedAtack() {
	if (numAtack1 <= 0) {
		cout << "\nHas usado el ataque el numero maximo de veces. Prueba con otro.\n";
	}

}

void finalGame() {
	delay(5);
	system("cls");
	cout << "\nFIN DEL JUEGO, GRACIAS POR JUGARLO !!!\n";
	cancion();

}


int main() {

	startGame();

	while (heroIsAlive1 == true && (enemyIsAlive1 == true || heroIsAlive1 == true && enemyIsAlive2 == true)) {

		if (heroHealth1 <= 0) {
			heroHealth1 = 0;
			heroIsAlive1 = false;
			cout << "\nLos enemigos han ganado el combate !!!\n";
			finalGame();
			break;
		}

		chooseAtack();

		if (directAtack == "l") {
			if (enemyHealth2 <= 0) {
				enemyIsAlive2 = false;
				enemyHealth2 = 0;
				cout << "\nEl enemigo " << enemyName2 << " ya ha sido derrotado. Es el momento de atacar a " << enemyName1 << ".\n";
			}
			else if (enemyIsAlive2) {
				atackTypes();
			}
			if (typeAtack == "1") {
				numAtack1 = numAtack1 - 1;
				if (numAtack1 > 0) {
					int heroDamage1 = 1 + rand() % (500 - 1);
					enemyHealth2 = enemyHealth2 - heroDamage1;
					if (enemyHealth2 <= 0) {
						enemyIsAlive2 = false;
						enemyHealth2 = 0;

					}
					else if (enemyIsAlive2) {
						int enemyDamage2 = 1 + rand() % (100 - 1);
						cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth2 << " puntos de vida\n";
						cout << "\nEl enemigo te va atacar de vuelta\n";
						heroHealth1 = heroHealth1 - enemyDamage2;
						if (heroHealth1 <= 0) {
							heroHealth1 = 0;
							heroHealth1 = false;
							cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho " << enemyDamage2 << " de dano\n";

						}
						else if (heroIsAlive1) {
							cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
						}

					}
				}
				else if (numAtack1 <= 0) {
					cout << "\nHas usado el ataque el numero maximo de veces. Prueba con otro.\n";
				}
			}
			if (typeAtack == "2") {
				int heroDamage1 = 1 + rand() % (400 - 1);
				enemyHealth2 = enemyHealth2 - heroDamage1;
				if (enemyHealth2 <= 0) {
					enemyIsAlive2 = false;
					enemyHealth2 = 0;
					cout << "\nEl enemigo " << enemyName2 << " ha sido derrotado\n";
				}
				else if (enemyIsAlive2) {
					int enemyDamage2 = 1 + rand() % (100 - 1);
					cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth2 << " puntos de vida\n";
					cout << "\nEl enemigo te va atacar de vuelta\n";
					heroHealth1 = heroHealth1 - enemyDamage2;
					if (heroHealth1 <= 0) {
						heroHealth1 = 0;
						heroHealth1 = false;
						cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho " << enemyDamage2 << " de dano\n";
					}
					else if (heroIsAlive1) {
						cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
					}
				}
			}
			if (typeAtack == "3") {
				int heroDamage1 = 1 + rand() % (200 - 1);
				enemyHealth2 = enemyHealth2 - heroDamage1;
				if (enemyHealth2 <= 0) {
					enemyIsAlive2 = false;
					enemyHealth2 = 0;
					cout << "\nEl enemigo " << enemyName2 << " ha sido derrotado\n";
				}
				else if (enemyIsAlive2) {
					int enemyDamage2 = 1 + rand() % (100 - 1);
					cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth2 << " puntos de vida\n";
					cout << "\nEl enemigo te va atacar de vuelta\n";
					heroHealth1 = heroHealth1 - enemyDamage2;
					if (heroHealth1 <= 0) {
						heroHealth1 = 0;
						heroHealth1 = false;
						cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho" << enemyDamage2 << " de daño\n";
					}
					else if (heroIsAlive1) {
						cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
					}
				}
			}
		}



		if (directAtack == "d") {
			int enemyDamage1 = 1 + rand() % (500 - 1);
			if (enemyHealth1 <= 0) {
				enemyIsAlive1 = false;
				enemyHealth1 = 0;
				cout << "\nEl enemigo " << enemyName1 << " ya ha sido derrotado. Es el momento de atacar a " << enemyName2 << ".\n";
			}
			else if (enemyIsAlive1) {

				atackTypes();

				if (typeAtack == "1") {
					numAtack2 = numAtack2 - 1;
					if (numAtack2 > 0) {
						int heroDamage1 = 1 + rand() % (500 - 1);
						enemyHealth1 = enemyHealth1 - heroDamage1;
						if (enemyHealth1 <= 0) {
							enemyIsAlive1 = false;
							enemyHealth1 = 0;
							cout << "\nEl enemigo " << enemyName1 << " ha sido derrotado\n";
						}
						else if (enemyIsAlive1) {
							cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth1 << " puntos de vida\n";
							cout << "\nEl enemigo te va atacar de vuelta\n";
							heroHealth1 = heroHealth1 - enemyDamage1;
							if (heroHealth1 <= 0) {
								heroHealth1 = 0;
								heroHealth1 = false;
								cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho " << enemyDamage1 << " de dano\n";
							}
							else if (heroIsAlive1) {
								cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
							}
						}
					}
					else limitedAtack();
				}

				if (typeAtack == "2") {
					int heroDamage1 = 1 + rand() % (400 - 1);
					enemyHealth1 = enemyHealth1 - heroDamage1;
					if (enemyHealth1 <= 0) {
						enemyIsAlive1 = false;
						enemyHealth1 = 0;
						cout << "\nEl enemigo " << enemyName1 << " ha sido derrotado\n";
					}
					else if (enemyIsAlive1) {
						cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth1 << " puntos de vida\n";
						cout << "\nEl enemigo te va atacar de vuelta\n";
						heroHealth1 = heroHealth1 - enemyDamage1;
						if (heroHealth1 <= 0) {
							heroHealth1 = 0;
							heroHealth1 = false;
							cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho " << enemyDamage1 << " de dano\n";
						}
						else if (heroIsAlive1) {
							cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
						}
					}
				}
				if (typeAtack == "3") {
					int heroDamage1 = 1 + rand() % (200 - 1);
					enemyHealth1 = enemyHealth1 - heroDamage1;
					if (enemyHealth1 <= 0) {
						enemyIsAlive1 = false;
						enemyHealth1 = 0;
						cout << "\nEl enemigo " << enemyName1 << " ha sido derrotado\n";
					}
					else if (enemyIsAlive1) {
						cout << "\nTras el ataque, la vida del enemigo es de " << enemyHealth1 << " puntos de vida\n";
						cout << "\nEl enemigo te va atacar de vuelta\n";
						heroHealth1 = heroHealth1 - enemyDamage1;
						if (heroHealth1 <= 0) {
							heroHealth1 = 0;
							heroHealth1 = false;
							cout << "\nEl heroe ha sido derrotado, el enemigo le ha hecho " << enemyDamage1 << " de dano\n";
						}
						else if (heroIsAlive1) {
							cout << "\nLa vida del heroe tras el ataque es de " << heroHealth1 << "\n";
						}

					}
				}
			}
		}
	}
	if (!enemyIsAlive1 && !enemyIsAlive2) {
		cout << "\nLos dos enemigos han sido eliminados\n";
		finalGame();

	}
}