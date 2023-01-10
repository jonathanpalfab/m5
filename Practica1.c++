#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP1 = 100;
string enemyName1 = "Zombie";
bool enemyIsAlive1 = true;

//Atributos del enemigo 2
int enemyHP2 = 150;
string enemyName2 = "Creeper";
bool enemyIsAlive2 = true;

//Atributos del personaje
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

void checkEnemyStatus(string enemyName, int& enemyHP, bool& enemyIsAlive) {
    if (enemyHP <= 0) {
        cout << "Te has cargado al enemigo " << enemyName << " \n";
        enemyHP = 0;
        enemyIsAlive = false;
        
    }
    else {
        cout << "El enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida\n";
        enemyIsAlive = true;
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




int heroAttackEnemy(string& enemyName, int& damage, int& enemyHP) {
    cout << "Atacas al enemigo " << enemyName << " y le haces un danyo de " << damage << " \n";
    return enemyHP - damage;
}




void enemyAttack(string& enemyName, int& enemyDamage, int& heroHP, bool& heroIsAlive) {
    heroHP = heroHP - enemyDamage;
    if (heroHP > 0) {
        cout << "El enemigo " << enemyName << " te ha atacado y te quedan " << heroHP << " puntos de vida\n";
    }
    else {
        cout << "El enemigo " << enemyName << " te ha atacado y te ha matado. El mundo esta condenado. \n";
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
            heroAttackEnemy(enemyName1, heroDamage, enemyHP1);
            checkEnemyStatus(enemyName1, enemyHP1, enemyIsAlive1);
        }
        else {
            //ATACAMOS AL ENEMIGO 2
            heroAttackEnemy(enemyName2, heroDamage, enemyHP2);
            checkEnemyStatus(enemyName2, enemyHP2, enemyIsAlive2);
        }
        //ATACA EL ENEMIGO 1 SI EST� VIVO Y EL H�ROE TAMBI�N
        if (enemyIsAlive1 && heroIsAlive) {
            int enemyDamage1(30 + rand() % 20);
            enemyAttack(enemyName1,heroDamage,enemyHP1, heroIsAlive);
        }
        //ATACA EL ENEMIGO 2 SI EST� VIVO Y EL H�ROE TAMBI�N
        if (enemyIsAlive2 && heroIsAlive) {
            int enemyDamage2(30 + rand() % 20);
            enemyAttack(enemyName2, heroDamage, enemyHP2, heroIsAlive);
        }
    }
}

