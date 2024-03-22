// MFC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
const int PAUSA_ENTRE_CARACTERES = 20;
string characters[2] = { "Javi","Roberto" };
string ataques[4] = { "Jab a la napia","Gancho al menton","Crochet al higado","Manos arriba y bloquear" };
double damagesStamina[3] = { 10,15,20 };
double stats[8][4] = { {100,100,100,100},{80,120,80,120} };
double vidaPersonaje = stats[0][0];		double vidaRival = stats[1][0];
double atkPersonaje = stats[0][1];		double atkRival = stats[1][1];
double defensaPersonaje = stats[0][2];	double defensaRival = stats[1][2];
int staminaPersonaje = stats[0][3];		int staminaRival = stats[1][3];
int minutos = 5;
int contador = 0;
string character;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int randomAtaque() {
	if (vidaRival > ((vidaRival / 4) * 3) && staminaRival > ((staminaRival / 4) * 3)) {
		return rand() % 3;
	}
	else {
		return rand() % 4;
	}
	
}
int personaje() {
	bool atacando = true;
	int espacios;
	int superespacios = 0;
	while (atacando == true) {
		int numAtk;
		string ataque;
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\n";
		cout << "                                                        MINUTO: " << minutos << "\n"; cout << "\n"; 
		SetConsoleTextAttribute(hConsole, 6);
		cout << "  |#############################################|"; cout << "		       |#############################################|\n"; cout << "  | ";
		SetConsoleTextAttribute(hConsole, 4);
		espacios = 0; 
			cout << "HP:  ";
		for (double i = round(vidaPersonaje / (stats[0][0] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
		}
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		if (vidaPersonaje < 100) {
			cout << " ";
		}
		cout << "           " << round(vidaPersonaje) << "/" << stats[0][0]; SetConsoleTextAttribute(hConsole, 6); cout << " |"; cout << "		       |";
		SetConsoleTextAttribute(hConsole, 4);
		espacios = 0;
		cout << "HP:  ";
		for (double i = round(vidaRival / (stats[1][0] / 10)) ; i > 0; i--) {
			cout << "+ ";
			espacios++;
		} 
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		cout << "              " << round(vidaRival) << "/" << stats[1][0]; SetConsoleTextAttribute(hConsole, 6); cout << " |";
		cout << "\n";


		cout << "  | ";
		SetConsoleTextAttribute(hConsole, 13);
		espacios = 0;
		cout << "ATK: ";
		for (double i = round(atkPersonaje / (stats[0][1] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
		}
		espacios = 14 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		if (atkPersonaje < 100) {
			cout << " ";
		}
		cout << "   " << round(atkPersonaje) << "/" << stats[0][1]; SetConsoleTextAttribute(hConsole, 6); cout << " |"; cout << "		       |";
		SetConsoleTextAttribute(hConsole, 13);
		espacios = 0;
		cout << "ATK: ";
		for (double i = round(atkRival / (stats[1][1] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
			if (espacios > 10) {
				superespacios++;
			}
		}
		espacios = 14  - espacios;
		
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		if (atkRival < 100) {
			cout << " ";
		}
		cout << "    " << atkRival << "/" << stats[1][1]; SetConsoleTextAttribute(hConsole, 6); cout << " |";
		cout << "\n";

		SetConsoleTextAttribute(hConsole, 6); cout << "  | "; 
		SetConsoleTextAttribute(hConsole, 1);
		espacios = 0;
		cout << "DEF: ";
		for (double i = round(defensaPersonaje / (stats[0][2] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
		}
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "    ";
		}
		if (defensaPersonaje < 100) {
			cout << " ";
		}
		cout << "           " << round(defensaPersonaje) << "/" << stats[0][2]; SetConsoleTextAttribute(hConsole, 6); cout << " |"; cout << "		       |";
		SetConsoleTextAttribute(hConsole, 1); 
		espacios = 0;
		cout << "DEF: ";
		for (double i = round(defensaRival / (stats[1][2] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
		} 
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "    ";
		}
		cout << "              " << defensaRival << "/" << stats[1][2]; SetConsoleTextAttribute(hConsole, 6); cout << " |";
		cout << "\n";


		SetConsoleTextAttribute(hConsole, 6); cout << "  | ";
		SetConsoleTextAttribute(hConsole, 10);
		espacios = 0;
		cout << "ST:  ";
		for (int i = (staminaPersonaje / (stats[0][3] / 10)); i > 0; i--) {
			cout << "+ ";
			espacios++;
		}
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		if (staminaPersonaje < 100) {
			cout << " ";
		}
		cout << "           " << staminaPersonaje << "/" << stats[0][3]; SetConsoleTextAttribute(hConsole, 6); cout << " |"; cout << "		       |";
		SetConsoleTextAttribute(hConsole, 10);
		espacios = 0;
		cout << "ST:  ";
		for (int i = staminaRival / (stats[1][3] / 10); i > 0; i--) {
			cout << "+ ";
			espacios++;
		}
		espacios = 10 - espacios;
		for (int i = espacios; i > 0; i--) {
			cout << "  ";
		}
		if (staminaRival < 100) {
			cout << " ";
		}
		cout << "            " << staminaRival << "/" << stats[1][3]; SetConsoleTextAttribute(hConsole, 6); cout << " |\n";
		SetConsoleTextAttribute(hConsole, 6);
		cout << "  |#############################################|"; cout << "		       |#############################################|\n";
		



		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; 
		cout << "         ====================================================================================================\n";
		cout << "         =                                                  =                                               =\n";
		cout << "         =                 1-"; SetConsoleTextAttribute(hConsole, 9); cout << ataques[0]; SetConsoleTextAttribute(hConsole, 6); cout << "                 =             2-"; SetConsoleTextAttribute(hConsole, 9); cout << ataques[1]; SetConsoleTextAttribute(hConsole, 6); cout << "                =\n";
		cout << "         =                                                  =                                               =\n";
		cout << "         ====================================================================================================\n";
		cout << "         =                                                  =                                               =\n";
		cout << "         =                3-";  SetConsoleTextAttribute(hConsole, 9); cout << ataques[2]; SetConsoleTextAttribute(hConsole, 6); cout << "               =          4-"; SetConsoleTextAttribute(hConsole, 9); cout << ataques[3]; SetConsoleTextAttribute(hConsole, 6); cout << "            =\n";
		cout << "         =                                                  =                                               =\n";
		cout << "         ====================================================================================================\n"; SetConsoleTextAttribute(hConsole, 1); cout << "\n";
		cout << "\n"; 
		cout << "                                                   ELIGE TU ATAQUE: ";
		cin >> ataque;
		numAtk = stoi(ataque); cout << "\n"; SetConsoleTextAttribute(hConsole, 4);
		numAtk--;
		if (numAtk < 0 || numAtk > 3 ){
			cout << "                              La opcion es incorrecta, escoje entre las disponibles\n";
			Sleep(1000);
			system("CLS");
			
		}
		
		else if (numAtk == 3) {
			cout << "                                             Vas a " << ataques[3];
			numAtk = numAtk + 2;
			atacando = false;
			return numAtk;
		}
		else {
			cout << "                                          Vas a lanzar un " << ataques[numAtk];
			atacando = false;
			numAtk++;
			if (numAtk == 3) {
				numAtk++;
			}
			return numAtk;
		}
		
	}
}
int rival() {
	int numAtk = randomAtaque();
	if (numAtk == 0) {
		numAtk=1;
		
	}
	else if (numAtk == 1) {
		numAtk = 3;
		
	}
	else if (numAtk == 2) {
		numAtk = 7;
		
	}
	else {
		numAtk = -1;
	}
	return numAtk;
}

void pelea() {
	string ganador;
	int rounds = 1;
	bool exhaust = false;
	bool roundas = true;
	int atk1;
	int atk2;
	int fight;
	while (vidaPersonaje > 0 && vidaRival > 0 && rounds < 6) {
		if (minutos == 0) {
			cout << "							Descanso\n";
			Sleep(1500);
			minutos = 5;
			contador = 0;
			rounds++;
			cout << "				Recuperais 10 de vida y 15 de estamina";
			if (character == characters[0]) {
				atkRival = atkRival + 10;
			}
			if (character == characters[1]) {
				atkPersonaje = atkPersonaje + 10;
			}
			if (staminaPersonaje < stats[0][3]) {
				staminaPersonaje = staminaPersonaje + 15;
			}
			if (staminaRival < stats[1][3]) {
				staminaRival = staminaRival + 15;
			}
			if (vidaPersonaje < stats[0][0]) {
				vidaPersonaje = vidaPersonaje + 10;
			}
			if (vidaRival < stats[1][0]) {
				vidaRival = vidaRival + 10;
			}
			roundas = true;
			
			Sleep(1500);
			system("CLS");
		}
		else {
			character = characters[0];
			while (roundas == true) {
				switch (rounds) {
				case 1:
					cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@#     @@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@   "; Sleep(100); SetConsoleTextAttribute(hConsole, 1); cout << "##########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@@ @@@@@@@@@@ @@@@@@@@@ @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "##########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@#   #@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@  @@@@@     @@@@@:   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@+++@@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@ @@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@@:  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@    @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@ @@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@# %@@@@@@   @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@  @@@@@@@@@     @@@@@.   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@%-@@@@@@@ @@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "   ######## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@% -@@@@@@   @@@@@@@@@@@@      @@@@@@@@@@@@@    @@@@@@@@@  @@@@@@@   @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ########## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        #@@@@@@@@    @@@@=     #@@@@@@*          #@@@@@@@-      #@@@@@@@-   *@@@@+   %@@@@@@@@@@@=     "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ########## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(1000);
					roundas = false;
					break;
				case 2:
					cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@#     @@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ###########\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@@ @@@@@@@@@@ @@@@@@@@@ @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ############\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@#   #@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@  @@@@@     @@@@@:   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "###   #####  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@+++@@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@ @@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "     #####   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@@:  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    #####    \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@    @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@ @@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "   #####   # \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@# %@@@@@@   @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@  @@@@@@@@@     @@@@@.   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  #####   ## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@%-@@@@@@@ @@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " #####   ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@% -@@@@@@   @@@@@@@@@@@@      @@@@@@@@@@@@@    @@@@@@@@@  @@@@@@@   @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ##########  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        #@@@@@@@@    @@@@=     #@@@@@@*          #@@@@@@@-      #@@@@@@@-   *@@@@+   %@@@@@@@@@@@=     "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " #########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(1000);
					roundas = false;
					break;
				case 3:
					cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@#     @@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "###########  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@@ @@@@@@@@@@ @@@@@@@@@ @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ########## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@#   #@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@  @@@@@     @@@@@:   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "        #####\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@+++@@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@ @@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    #######  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@@:  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "##########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@    @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@ @@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "##########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@# %@@@@@@   @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@  @@@@@@@@@     @@@@@.   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ######## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@%-@@@@@@@ @@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "        #####\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@% -@@@@@@   @@@@@@@@@@@@      @@@@@@@@@@@@@    @@@@@@@@@  @@@@@@@   @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ########## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        #@@@@@@@@    @@@@=     #@@@@@@*          #@@@@@@@-      #@@@@@@@-   *@@@@+   %@@@@@@@@@@@=     "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "########### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(1000);
					roundas = false;
					break;
				case 4:
					cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@#     @@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "    ###  ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@@ @@@@@@@@@@ @@@@@@@@@ @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "   ###   ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@#   #@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@  @@@@@     @@@@@:   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ###    ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@+++@@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@ @@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ###     ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@@:  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ############\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@    @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@ @@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ############\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@# %@@@@@@   @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@  @@@@@@@@@     @@@@@.   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "        #### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@%-@@@@@@@ @@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "       ####  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@% -@@@@@@   @@@@@@@@@@@@      @@@@@@@@@@@@@    @@@@@@@@@  @@@@@@@   @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "      ####  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        #@@@@@@@@    @@@@=     #@@@@@@*          #@@@@@@@-      #@@@@@@@-   *@@@@+   %@@@@@@@@@@@=     "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "     ####    \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(1000);
					roundas = false;
					break;
				case 5:
					cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@#     @@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @@@@@@@@@  @@@@@@@@@ @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "  ###########\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@@ @@@@@@@@@@ @@@@@@@@@ @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ########### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@#   #@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@  @@@@@     @@@@@:   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "####         \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@+++@@@@@@  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@ @@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "###          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@@:  @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@@@@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "###########\n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@@@@@@@@@    @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@ @@@@@@@@@@     @@@@@.   #@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "###       ## \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          @@@@@# %@@@@@@   @@@@@@    @@@@@@   @@@@@    @@@@@@     @@@@@  @@@@@@@@@     @@@@@.   @@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "         ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@%-@@@@@@@ @@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@   @@@@@@@@@ @@@@@@@@   @@@@@@@@@@@@@@@@@ "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "         ### \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@% -@@@@@@   @@@@@@@@@@@@      @@@@@@@@@@@@@    @@@@@@@@@  @@@@@@@   @@@@@@@@@@@@@@@   "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << " ##########  \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        #@@@@@@@@    @@@@=     #@@@@@@*          #@@@@@@@-      #@@@@@@@-   *@@@@+   %@@@@@@@@@@@=     "; Sleep(100);  SetConsoleTextAttribute(hConsole, 1); cout << "##########   \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "          \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(200); SetConsoleTextAttribute(hConsole, 6); cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
					Sleep(1000);
					roundas = false;
					break;
				}
			}
			system("CLS");
			if (vidaRival > stats[1][0]) {
				vidaRival = stats[1][0];
			}
			if (staminaRival > stats[1][3]) {
				staminaRival = stats[1][3];
			}
			if (vidaPersonaje > stats[0][0]) {
				vidaPersonaje = stats[0][0];
			}
			if (staminaPersonaje > stats[0][3]) {
				staminaPersonaje = stats[0][3];
			}
			atk1 = personaje();
			Sleep(1500);
			system("CLS");
			atk2 = rival();
			fight = atk1 * atk2;
			Sleep(500);
				switch (fight) {
				case 1://Jab-Jab
					cout << "Ambos lanzais un jab a la napia\n";
					cout << "Perdeis estamina\n";
					staminaPersonaje = staminaPersonaje - damagesStamina[0];
					staminaRival = staminaRival - damagesStamina[0];
					contador++;
					break;
				case 3://Jab-Upper
					cout << "Gana jab a la napia   \n";
					cout << " El rival pierde " << round((damagesStamina[0] * atkPersonaje) / defensaRival) << " puntos de vida\n";
					vidaRival = vidaRival - round((damagesStamina[0] * atkPersonaje) / defensaRival);
					staminaPersonaje = staminaPersonaje - damagesStamina[0];
					staminaRival = staminaRival - damagesStamina[1];
					contador = contador + 2;
					break;
				case 7://Jab-Higado
					cout << "Gana el crochet al higado  \n";
					cout << " Pierdes " << round((damagesStamina[2] * atkRival) / defensaPersonaje) << " puntos de vida\n";
					vidaPersonaje = vidaPersonaje - round((damagesStamina[2] * atkRival) / defensaPersonaje);
					staminaPersonaje = staminaPersonaje - damagesStamina[0];
					staminaRival = staminaRival - damagesStamina[2];
					contador = 0;
					break;
				case 2://Upper-Jab
					cout << "Gana el jab a la napia  \n";
					cout << " Pierdes " << round((damagesStamina[0] * atkRival) / defensaPersonaje) << " puntos de vida\n";
					vidaPersonaje = vidaPersonaje - round((damagesStamina[0] * atkRival) / defensaPersonaje);
					staminaPersonaje = staminaPersonaje - damagesStamina[1];
					staminaRival = staminaRival - damagesStamina[0];
					contador = 0;
					break;
				case 6://Upper-Upper 
					cout << "Ambos lanzais un gancho al menton\n";
					cout << "Perdeis estamina\n";
					staminaPersonaje = staminaPersonaje - damagesStamina[1];
					staminaRival = staminaRival - damagesStamina[1];
					contador++;
					break;
				case 14://Upper-Higado
					cout << "Gana el crochet al higado  \n";
					cout << " El rival pierde " << round((damagesStamina[1] * atkPersonaje) / defensaRival) << " puntos de vida\n";
					vidaRival = vidaRival - round((damagesStamina[1] * atkPersonaje) / defensaRival);
					staminaPersonaje = staminaPersonaje - damagesStamina[1];
					staminaRival = staminaRival - damagesStamina[2];
					contador = contador + 2;
					break;
				case 4://Higado-Jab
					cout << "Gana el crochet al higado  \n";
					cout << " El rival pierde " << round((damagesStamina[2] * atkPersonaje) / defensaRival) << " puntos de vida\n";
					vidaRival = vidaRival - round((damagesStamina[2] * atkPersonaje) / defensaRival);
					staminaPersonaje = staminaPersonaje - damagesStamina[2];
					staminaRival = staminaRival - damagesStamina[0];
					contador = contador + 2;
					break;
				case 12://Higado-Upper
					cout << "Gana el gancho al menton  \n";
					cout << " Pierdes " << round((damagesStamina[1] * atkRival) / defensaPersonaje) << " puntos de vida\n";
					vidaPersonaje = vidaPersonaje - round((damagesStamina[1] * atkRival) / defensaPersonaje);
					staminaPersonaje = staminaPersonaje - damagesStamina[2];
					staminaRival = staminaRival - damagesStamina[1];
					contador = 0;
					break;
				case 28://Higado-Higado
					cout << "Ambos lanzais un crochet al higado\n";
					cout << "Perdeis estamina\n";
					staminaPersonaje = staminaPersonaje - damagesStamina[2];
					staminaRival = staminaRival - damagesStamina[2];
					contador++;
					break;
				case 5://Bloc jab
					cout << "Intentas bloquear el jab";
					vidaPersonaje = vidaPersonaje - round((((damagesStamina[0] * atkRival) / defensaPersonaje) / 2));
					staminaPersonaje = staminaPersonaje + 10;
					staminaRival = staminaRival - damagesStamina[0];
					if (character == characters[0]) {
						staminaPersonaje = staminaPersonaje + (contador * 1);
					}
					break;
				case 15://Bloc upper
					cout << "Intentas bloquear el gancho";
					vidaPersonaje = vidaPersonaje - round((((damagesStamina[1] * atkRival) / defensaPersonaje) / 2));
					staminaPersonaje = staminaPersonaje + 10;
					staminaRival = staminaRival - damagesStamina[1];
					if (character == characters[0]) {
						staminaPersonaje = staminaPersonaje + (contador * 1);
					}
					break;
				case 35://Bloc crochet
					cout << "Intentas bloquear el crochet";
					vidaPersonaje = vidaPersonaje - round((((damagesStamina[2] * atkRival) / defensaPersonaje) / 2));
					staminaPersonaje = staminaPersonaje + 10;
					staminaRival = staminaRival - damagesStamina[2];
					if (character == characters[0]) {
						staminaPersonaje = staminaPersonaje + (contador * 1);
					}
					break;
				case -1://Bloque jab
					cout << "El rival intenta bloquear tu jab";
					vidaRival = vidaRival - round((((damagesStamina[0] * atkPersonaje) / defensaRival) / 2));
					staminaRival = staminaRival + 10;
					staminaPersonaje = staminaPersonaje - damagesStamina[0];
					if (character == characters[1]) {
						staminaRival = staminaRival + (contador * 1);
					}
					break;
				case -2://Bloquea gancho
					cout << "El rival intenta bloquear tu gancho";
					vidaRival = vidaRival - ((((damagesStamina[1] * atkPersonaje) / defensaRival) / 2));
					staminaRival = staminaRival + 10;
					staminaPersonaje = staminaPersonaje - damagesStamina[1];
					if (character == characters[1]) {
						staminaRival = staminaRival + (contador * 1);
					}
					break;
				case -4://Bloquea crochet
					cout << "El rival intenta bloquear tu crochet";
					vidaRival = vidaRival - ((((damagesStamina[2] * atkPersonaje) / defensaRival) / 2));
					staminaRival = staminaRival + 10;
					staminaPersonaje = staminaPersonaje - damagesStamina[2];
					if (character == characters[1]) {
						staminaRival = staminaRival + (contador * 1);
					}
					break;
				case -5://Bloc-Bloc
					cout << "Ambos intentais bloquear";
					if (character == characters[0]) {
						staminaRival = staminaRival + 15;
						staminaPersonaje = staminaPersonaje + 15 + (contador * 2);
					}
					if (character == characters[1]) {
						staminaRival = staminaRival + 15 + (contador * 2);
						staminaPersonaje = staminaPersonaje + 15;
					}
					break;
				}

				Sleep(1000);
				if (exhaust == true) {
					cout << "El rival recupera la mitad de la estamina\n";
					staminaRival = (stats[1][3] / 2);
					exhaust = false;
				}
				if (staminaRival <= 0) {
					staminaRival = 0;
					cout << "El rival esta sin aire, es tu momento!!\n";
					exhaust = true;
				}
				if (contador >= 5 && character == characters[0]) {
					cout << "Castigar al rival tan seguido hace que baje su defensa!\n";
					defensaRival = defensaRival - ((defensaRival/100)*20);
					defensaRival = (defensaRival);
					contador = 0;
					Sleep(1000);
				}
				else if (contador >= 5 && character == characters[1]) {
					cout << "La paliza que te esta dando hace que disminuia du defensa!\n";
					defensaPersonaje = (defensaPersonaje - 20);
					Sleep(1000);
					contador = 0;
				}
				minutos--;
				system("CLS");
			}
		}

		if (vidaPersonaje <= 0) {
			ganador = characters[1];
		}
		else if (vidaRival <= 0) {
			ganador = characters[0];
		}
		cout << "El ganador es " << ganador;

	}


void intro() {

	SetConsoleTextAttribute(hConsole, 6);
	cout << "	Antes de empezar, te recuerdo que este juego esta hecho en las dimensiones del cmd en formato ventana.\n";

	Sleep(1500); SetConsoleTextAttribute(hConsole, 1); cout << "			     	         Cuando estes listo, presiona Enter!\n";
	cout << "\n";
	cout << "							  ";
	SetConsoleTextAttribute(hConsole, 6); cin.get();
	system("CLS");

	SetConsoleTextAttribute(hConsole, 1);
	cout << "\n";
	Sleep(200);  cout << "				";		  cout << "########################*###########**###########+#####%\n";
	Sleep(200);  cout << "				";        cout << "######################  =#########*  +#######1#=  #####%\n";
	Sleep(200);  cout << "				";        cout << "####################=   =#######*    +#######+    #####%\n";
	Sleep(200);  cout << "				";        cout << "##################=     =#####*      +#####+      #####%\n";
	Sleep(200);  cout << "				";        cout << "################+       =####+       +###+        #####%\n";
	Sleep(200);  cout << "				";        cout << "##############+         =###+        +##*         #####%\n";
	Sleep(200);  cout << "				";        cout << "##########%@            =#-          #*-          #####%\n";
	Sleep(200);  cout << "				";        cout << "#########%"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@@@@@@@@@@@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "#"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@@@@@@@"; SetConsoleTextAttribute(hConsole, 1); cout << "##"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@@@@@@@"; SetConsoleTextAttribute(hConsole, 1); cout << "%####%\n";
	Sleep(200);  cout << "				";        cout << "########*      "; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@+ +@@@@"; SetConsoleTextAttribute(hConsole, 1); cout << "##         +#"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@       "; SetConsoleTextAttribute(hConsole, 1); cout << "#####%\n";
	Sleep(200);  cout << "				";        cout << "########"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@#  *@@@+  "; SetConsoleTextAttribute(hConsole, 1); cout << " "; SetConsoleTextAttribute(hConsole, 6); cout << "@@@";  SetConsoleTextAttribute(hConsole, 1); cout << "%%";     SetConsoleTextAttribute(hConsole, 6); cout << "@%%%%%%%%+"; SetConsoleTextAttribute(hConsole, 1); cout << "#"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@@       "; SetConsoleTextAttribute(hConsole, 1); cout << "#####%\n";
	Sleep(200);  cout << "				";        cout << "#######"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@%= +@@@+  #@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "#"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@@@@@@@"; SetConsoleTextAttribute(hConsole, 1); cout << "##"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@        "; SetConsoleTextAttribute(hConsole, 1); cout << "#####%\n";
	Sleep(200);  cout << "				";        cout << "######"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@+ +@@@"; SetConsoleTextAttribute(hConsole, 1); cout << " ";  SetConsoleTextAttribute(hConsole, 6); cout << "  *@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "#"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@@    "; SetConsoleTextAttribute(hConsole, 1); cout << "=###"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@       "; SetConsoleTextAttribute(hConsole, 1); cout << "######%\n";
	Sleep(200);  cout << "				";        cout << "#####"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@@= =%@@%  +@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "###"; SetConsoleTextAttribute(hConsole, 6); cout << "@@@"; SetConsoleTextAttribute(hConsole, 1); cout << "#   ####"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@@@%%%%@@"; SetConsoleTextAttribute(hConsole, 1); cout << "#######%\n";
	Sleep(200);  cout << "				";        cout << "####"; SetConsoleTextAttribute(hConsole, 6); cout << "%@@%+  "; SetConsoleTextAttribute(hConsole, 1); cout << " "; SetConsoleTextAttribute(hConsole, 6); cout << "%%%= =@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "#-="; SetConsoleTextAttribute(hConsole, 6); cout << "%%%%  "; SetConsoleTextAttribute(hConsole, 1); cout << "####+  #"; SetConsoleTextAttribute(hConsole, 6); cout << "%%%%@@@@%"; SetConsoleTextAttribute(hConsole, 1); cout << "#######%\n";
	Sleep(200);  cout << "				";        cout << "######=        +####=       *###*        =#############%\n";
	Sleep(200);  cout << "				";        cout << "######=       =####=       *###*       =###############%\n";
	Sleep(200);  cout << "				";        cout << "######=     =######      +#####=      #################%\n";
	Sleep(200);  cout << "				";        cout << "######=   =########    +#######=    ###################%\n";
	Sleep(200);  cout << "				";        cout << "######=  ##########  +#########=  *####################%\n";
	Sleep(200);  cout << "				";        cout << "######**###########+###########**######################%\n";
	Sleep(200);
	cout << " \n";
	SetConsoleTextAttribute(hConsole, 6);
	string mensaje_entrada = "			     Bienvenidos al evento de lucha mas importante de la historia!\n";
	for (char c : mensaje_entrada) {
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(1000);
	cout << " \n";
	string text1 = "		  La escuela de grado superior Monalu, situada en La Sagrera, Barcelona, lleva decadas\n";	string text2 = "			       ocultando a los mejores peladores del mundo como profesores. \n";
	string text3 = "		   Despues de que Conor Manca Mcgregor, antiguo campeon de la UFC de peso pluma y ligero,\n";	string text4 = "		      llevase un icontable tiempo en paradero desconocido, hace unas semanas salio\n";
	string text5 = "		         a la luz que habia estado entrenando durante todos este tiempo en secreto\n";	string text6 = "			bajo la identidad de Roberto Manca, un profesor de Python de grado superior.\n";
	string text7 = "		     A raiz de esto, se descubrio que varios ex-campeones de la UFC tambien estaban\n";	string text8 = "		      de incognito en Monlau bajo la apariencia de otros profesores de informatica. \n";
	string text9 = "	 En ese momento, el mundo hablo, y se pusieron en marcha las peleas mas deseadas de los ultimos tiempos.\n";	string text10 = "					  ASI NACIO MONLAU FIGHTING CHAMPIONSHIP.\n";
	for (char d : text1 + text2) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(1500); cout << "\n";
	for (char d : text3 + text4 + text5 + text6) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(1500); cout << "\n";
	for (char d : text7 + text8) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(1500); cout << "\n";
	for (char d : text9 + text10) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(500);
	system("CLS");
}
void tutorial() {
	string tut;
	bool tuto = true;
	while (tuto == true) {
	SetConsoleTextAttribute(hConsole, 6);
	string texttut1 = "			     El evento se celebrara el 22 de marzo en Monlau, la Sagrera.\n";
	string texttut2 = "			   Hasta ese dia, los alumnos de esta institucion han desarrollado\n";
	string texttut4 = "				    un videojuego para simular los combates!!\n";
	string texttut3 = "				   Deseas hacer el tutorial de este juego(S/N)? ";
	for (char d : texttut1 + texttut2 + texttut4) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	Sleep(500);
	cout << "\n";
	SetConsoleTextAttribute(hConsole, 1);
	for (char d : texttut3) {
		cout << d << flush;
		this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
	}
	
		cin >> tut;
		if (tut == "S") {
			Sleep(500);
			cout << "\n";
			SetConsoleTextAttribute(hConsole, 4);
			string perf = "						    Perfecto\n";
			for (char d : perf) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
			}
			Sleep(500);
			system("CLS");
			SetConsoleTextAttribute(hConsole, 6);
			string khabib1= "                            Para empezar deberas escojer un personaje para jugar al juego.\n";
			string khabib2 = "          Podras elegir entre los peleadores del evento principal: Conor Manca Mcgregor o Javier Salmagomedov.\n";
			string khabib3 = "             Estos peleadores, de estilos muy diferentes, tienen diferentes caracterisiticas y habilidades.\n";
			string khabib4 = "                        Para ganar el combate, primero deberas entender sus atributos y poderes.\n";
			for (char d : khabib1 + khabib2 + khabib3 + khabib4) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
			}
			string khabib5 = "                                          Empecemos con las estadisticas! \n";
			SetConsoleTextAttribute(hConsole, 1);
			cout << "\n";
			Sleep(500);
			for (char d : khabib5) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
			}
			cout << "\n"; cout << "\n";
			SetConsoleTextAttribute(hConsole, 4);
			cout << "			   @@@@@@  @@@@@@   \n";														Sleep(100);
			cout << "			  @@####@@@@####@@ \n";															Sleep(100);
			cout << "			 @@##############@@\n"; 														Sleep(100);
			cout << "			 @@##############@@";  cout << "			    Vida / HP\n";											Sleep(100);
			cout << "			 @@@############@@@"; SetConsoleTextAttribute(hConsole, 6);   cout << "          El atributo mas importante del personaje\n";			Sleep(100); SetConsoleTextAttribute(hConsole, 4);
			cout << "			   @@%########%@@   "; SetConsoleTextAttribute(hConsole, 6);    cout << "            Cuando llegue a 0, este perecera...\n"; 		Sleep(100); SetConsoleTextAttribute(hConsole, 4);
			cout << "			      @%####%@      \n";														Sleep(100);
			cout << "			       @@%%@@       \n";														Sleep(100);
			cout << "			         @@         \n";														Sleep(100);
			cout << "\n"; cout << "\n"; Sleep(1000);
			SetConsoleTextAttribute(hConsole, 0);
			SetConsoleTextAttribute(hConsole, 13);
			cout << "		                ######:	 \n";														Sleep(100);
			cout << "		            ####:.....##:	\n";															Sleep(100);
			cout << "		           ##...#:......##	\n"; 														Sleep(100);
			cout << "		          #..####........#:";  cout << "			  Ataque / ATK\n";											Sleep(100);
			cout << "		         ##....##:....:.:#:"; SetConsoleTextAttribute(hConsole, 6);   cout << "          Sirve para bajar vida a tu contrincante\n";			Sleep(100); SetConsoleTextAttribute(hConsole, 13);
			cout << "		        :##:.....####..:#:	"; SetConsoleTextAttribute(hConsole, 6);    cout << "      Puede ir aumentando durante la pelaea\n"; 		Sleep(100); SetConsoleTextAttribute(hConsole, 13);
			cout << "		       #-..##:........###	 \n";														Sleep(100);
			cout << "		       #-.....##..###		 \n";														Sleep(100);
			cout << "		        -#-...-#=:			 \n";														Sleep(100);
			cout << "		          -###-			\n";
			cout << "\n"; cout << "\n"; Sleep(1000);
			SetConsoleTextAttribute(hConsole, 0);
			SetConsoleTextAttribute(hConsole, 1);

			cout << "			 =+++++++++++++++= \n";														Sleep(100);
			cout << "			 +=##############=\n";															Sleep(100);
			cout << "			 +=##############=\n"; 														Sleep(100);
			cout << "			 +=##############=";  cout << "			   Defensa / DEF\n";											Sleep(100);
			cout << "			 +=##############="; SetConsoleTextAttribute(hConsole, 6);   cout << "            Hace que los golpes te quiten menos vida\n";			Sleep(100); SetConsoleTextAttribute(hConsole, 1);
			cout << "			 +=##############="; SetConsoleTextAttribute(hConsole, 6);    cout << "           Dependiendo del golpe, puedes ser reducida\n"; 		Sleep(100); SetConsoleTextAttribute(hConsole, 1);
			cout << "			  +=###########=+  \n";														Sleep(100);
			cout << "			   +=#########=+	  \n";														Sleep(100);
			cout << "			     +=#####=+	  \n";														Sleep(100);
			cout << "			        +++		 \n";

			cout << "\n"; cout << "\n"; Sleep(1000);
			SetConsoleTextAttribute(hConsole, 0);
			SetConsoleTextAttribute(hConsole, 10);


			cout << "			         @@@   \n";														Sleep(100);
			cout << "			        @@@ 	\n";															Sleep(100);
			cout << "			       @@@	\n"; 														Sleep(100);
			cout << "			      @@@		";  cout << "		     Energia / ST\n";											Sleep(100);
			cout << "			     @@@@@@@@	"; SetConsoleTextAttribute(hConsole, 6);   cout << "               Cada habilidad consumira cierta energia\n";			Sleep(100); SetConsoleTextAttribute(hConsole, 10);
			cout << "			        @@@@	"; SetConsoleTextAttribute(hConsole, 6);    cout << "                 Si te quedas sin, estaras vulnerable\n"; 		Sleep(100); SetConsoleTextAttribute(hConsole, 10);
			cout << "			       @@@ 	 \n";														Sleep(100);
			cout << "			      @@		 \n";														Sleep(100);
			cout << "			     @		 \n";														Sleep(100);
			cout << "\n"; cout << "\n"; cout << "\n";
			Sleep(1500); SetConsoleTextAttribute(hConsole, 6);

			cout << "					       ";
			string continuar = "Presiona Enter para escojer personaje!\n";
			for (char d : continuar) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
			}
			cout << "\n";
			cout << "							  ";
			cin.get();
			tut = "N";
			system("CLS");
		}
		else if (tut == "N") {
			int personaje;
			Sleep(500);
			cout << "                                                  Que personajes eliges para jugar?\n"; cout << "\n";
			Sleep(500);
			cout << "                            1-Conor Manca                  |               2-Javier Salvagomedov";
			cout << "                                                                 ";  cin >> personaje;
			system("CLS");
			SetConsoleTextAttribute(hConsole, 6);
			if (personaje == 1) {
				cout << "                              	                                        :%.                            \n"; Sleep(75);
				cout << "                                                                 -=:*@%@@@%%+.                        \n"; Sleep(75);
				cout << "                                                                +.%@+:     :+%@@*.                    \n";	Sleep(75);
				cout << "                                                               %+@=            =@@=                   \n";	Sleep(75);
				cout << "                                                               *@.     %%.       #@*                  \n";	Sleep(75);
				cout << "                                                               #*  @@ ...   @@    %@=                 \n";	Sleep(75);
				cout << "                                                               %*  @@       @@    .@@                 \n";	Sleep(75);
				cout << "                                                               =@ :@@       @@    .@@                 \n";	Sleep(75);
				cout << "                                 .#%%%+.                        #%     _   _      -@+                 \n";	Sleep(75);
				cout << "                                :@@:  :+%@*%@@@*                 #%.    @@@      -@+                  \n";	Sleep(75);
				cout << "                               -@@@#%@+  .%++ :@*++++++====-----::+@#:         .#@#+==-:.             \n";	Sleep(75);
				cout << "                               *@ -@@@.   %#+: @+             ...:::-#@@#=--+%@@@-    .=#@@@-         \n";	Sleep(75);
				cout << "                               ##    -@:  -@--+@#                       ..::.   =@*         %#        \n";	Sleep(75);
				cout << "                               =@:   :@=.=@@@*+-                                 +@#       .@*        \n";	Sleep(75);
				cout << "                                +@=..*@@@%=                 :--:.                 #@@    .#@-         \n";	Sleep(75);
				cout << "                                  +@@@:                   -@=  .=%@@*@@@@-         #@%#@@*            \n";	Sleep(75);
				cout << "                                                         %#:+##=   :@:-:=@   .-+*%@%@@@.              \n";	Sleep(75);
				cout << "                                                   .+:  .@-         @=*=:@%#*+-:     %@#              \n";	Sleep(75);
				cout << "                                                        .@+         =@..=@=          :@@%             \n";	Sleep(75);
				cout << "                                                    :#+. #@+       -%@@@*.            .@@-            \n";	Sleep(75);
				cout << "                                                        - *@@+=*%@@%-                  @%             \n";	Sleep(75);
				cout << "                                                      -+    +##*=.                   .@#              \n";	Sleep(75);
				cout << "                                                                                     %%               \n";	Sleep(75);
				cout << "                                                                                  -%@#                \n";	Sleep(75);
				cout << "                  # # #    #    ##  #  # # #    #                               =@##@.                \n";	Sleep(75);
				cout << "                  # # #   # #   # # #  #       # #                            +@* -@.                 \n";	Sleep(75);
				cout << "                  #   #  # # #  #  ##  # # #  # # #                         %@-  -@-                  \n";	Sleep(75);
				cout << "                                                                         :%%:   .@+                   \n";	Sleep(75);
				cout << "                                                                       =@#.     @+                    \n";	Sleep(75);
				cout << "                                                                     +@*       #%                     \n";	Sleep(75);
				cout << "                                                                    .%=       -@                      \n";	Sleep(75);
				cout << "                                                                     %*        %%.                    \n";	Sleep(75);
				cout << "                                                                     ##         -@#.                  \n";	Sleep(75);
				cout << "                                                                     +%           -@*                 \n";	Sleep(75);
				cout << "                                                            .#%%%#=  :@.            +@+               \n";	Sleep(75);
				cout << "                                                            *@@@@@@@@*@.      .*@@@@%#@@.             \n";	Sleep(75);
				cout << "                                                            -@@@@@@@@@*       %@@@@@@@@@:             \n";	Sleep(75);
				cout << "                                                              .*%%*-           #@@@@@=  		 	   \n";	Sleep(75);
				Sleep(2000);
				tuto = false;
			}
			else   {
				cout << "                              	                                        :%.                            \n"; Sleep(75);
				cout << "                                                                 -=:*@%@@@%%+.                        \n"; Sleep(75);
				cout << "                                                                +.%@+:     :+%@@*.                    \n";	Sleep(75);
				cout << "                                                               %+@=            =@@=                   \n";	Sleep(75);
				cout << "                                                               *@.     %%.       #@*                  \n";	Sleep(75);
				cout << "                                                               #*  @@ ...   @@    %@=                 \n";	Sleep(75);
				cout << "                                                               %*  @@       @@    .@@                 \n";	Sleep(75);
				cout << "                                                               =@ :@@       @@    .@@                 \n";	Sleep(75);
				cout << "                                 .#%%%+.                        #%     _   _      -@+                 \n";	Sleep(75);
				cout << "                                :@@:  :+%@*%@@@*                 #%.    @@@      -@+                  \n";	Sleep(75);
				cout << "                               -@@@#%@+  .%++ :@*++++++====-----::+@#:         .#@#+==-:.             \n";	Sleep(75);
				cout << "                               *@ -@@@.   %#+: @+             ...:::-#@@#=--+%@@@-    .=#@@@-         \n";	Sleep(75);
				cout << "                               ##    -@:  -@--+@#                       ..::.   =@*         %#        \n";	Sleep(75);
				cout << "                               =@:   :@=.=@@@*+-                                 +@#       .@*        \n";	Sleep(75);
				cout << "                                +@=..*@@@%=                 :--:.                 #@@    .#@-         \n";	Sleep(75);
				cout << "                                  +@@@:                   -@=  .=%@@*@@@@-         #@%#@@*            \n";	Sleep(75);
				cout << "                                                         %#:+##=   :@:-:=@   .-+*%@%@@@.              \n";	Sleep(75);
				cout << "                                                   .+:  .@-         @=*=:@%#*+-:     %@#              \n";	Sleep(75);
				cout << "                                                        .@+         =@..=@=          :@@%             \n";	Sleep(75);
				cout << "                                                    :#+. #@+       -%@@@*.            .@@-            \n";	Sleep(75);
				cout << "                                                        - *@@+=*%@@%-                  @%             \n";	Sleep(75);
				cout << "                                                      -+    +##*=.                   .@#              \n";	Sleep(75);
				cout << "                                                                                     %%               \n";	Sleep(75);
				cout << "                                                                                  -%@#                \n";	Sleep(75);
				cout << "                                                                                =@##@.                \n";	Sleep(75);
				cout << "                # #    #    #   #  #                                        +@* -@.                   \n";	Sleep(75);
				cout << "                  #   # #    # #   #                                      %@-  -@-                    \n";	Sleep(75);
				cout << "              # # #  # # #    #    #                                   :%%:   .@+                     \n";	Sleep(75);
				cout << "                                                                       =@#.     @+                    \n";	Sleep(75);
				cout << "                                                                     +@*       #%                     \n";	Sleep(75);
				cout << "                                                                    .%=       -@                      \n";	Sleep(75);
				cout << "                                                                     %*        %%.                    \n";	Sleep(75);
				cout << "                                                                     ##         -@#.                  \n";	Sleep(75);
				cout << "                                                                     +%           -@*                 \n";	Sleep(75);
				cout << "                                                            .#%%%#=  :@.            +@+               \n";	Sleep(75);
				cout << "                                                            *@@@@@@@@*@.      .*@@@@%#@@.             \n";	Sleep(75);
				cout << "                                                            -@@@@@@@@@*       %@@@@@@@@@:             \n";	Sleep(75);
				cout << "                                                              .*%%*-           #@@@@@=  		 	   \n";	Sleep(75);
				Sleep(2000);
				tuto = false;
			}
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "\n";
			cout << "							";
			string punt = "...\n";
			for (char d : punt) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(200));
			}
			cout << "\n";
			string codaz = "		  Parece que tu respuesta no es valida. Si no quieres recibir un codazo por parte\n";
			string codaz2 = "		      de Manca, escribe S para hacer el tutorial o N para empezar a jugar...\n";
			for (char d : codaz + codaz2) {
				cout << d << flush;
				this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
			}
		}
		system("CLS");
	}

}

int main() {
	srand(time(NULL));
	intro();
	tutorial();
	SetConsoleTextAttribute(hConsole, 4);
                                                                                                                                                   
	cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; 
	cout <<"                                         @%                  *@@@@+               :@ .         .===-:=*+    \n";		Sleep(75);
    cout <<"                    .+#%@@@@@%@@@@      @@@@@#       :@%@@@.=@@@@@               +@@@@@%-  :#@@@*%@@@@@@@@@:   \n";	Sleep(75);
    cout <<"                  *@@@@@@@@@@%@@@@@@   @*%@@@%      #@@@@@@@@@@@%               #@@@@@@  @@@@@@@%%@@@@@=%%    \n";	Sleep(75);
    cout <<"                   =@@@@@@@@@*.     : #*@@@@%     :*@@@@#  *@@@@    #=%.       #@@@@@@  @@@@%@@@@@@@-@@@     \n";	Sleep(75);
    cout <<"                    =@@@@@:          :#@@@@%     -*@@@%.   @@@@=   +%@@@*     =@@@@@@  #@@@%#@@@@+*@@@        \n";	Sleep(75);
    cout <<"                    -@@@@@@          @%@@@@     -@@@%-      +@%   =@@@@#:    .@@@@@@        @=*@+@          \n";		Sleep(75);
    cout <<"                    @%@@@@+-*%%.    *@@@@*:    -@@@#+    :*+     -@@@@+   ++%@@@@@@-       #+###@           \n";		Sleep(75);
    cout <<"                   *@@%@@@@@@%@@=   @@@@#+    :%@@@+ :@@@@@@@:   @@@@%=@%@@@@@@@@@#       .%+##@            \n";		Sleep(75);
    cout <<"                   @@@@@@@@@@@@@@: #@@@@%    .*@@@*    @@@@@@@@ #@@@@@@@@@@@@@@@@@:       @*@@**            \n";		Sleep(75);
    cout <<"                  %@@@@@#          @@@@@*    #@@@%   :@@@@@@@@+.@@@@@@@@@@.=@@@@@=       -@#@+@             \n";		Sleep(75);
    cout <<"                 :@@@@@-          :@@@@@    =@@@@. .@@@@@@@@@+ -@@@@@@#:   #@@@@+-       @+@@@*             \n";		Sleep(75);
    cout <<"                 @@@@@*           =@@@@=    =@@@#*@@@@@=-@@@@: #@@@++      %@@@@ :       @#@@@.             \n";		Sleep(75);
    cout <<"                 @@@@%            -@@@@      @@@@@@@%:  *@@%#. #@@@-      .@@@%@:        +@@@@              \n";		Sleep(75);
    cout <<"                -%@@@=             #@@#        #@@@+.   @@@@+   :@@=        @@@@           =@@              \n";		Sleep(75);
    cout <<"                  %@@                #@                 .@@@=                #@@            +@              \n";		Sleep(75);
    cout <<"                   +@                 +                    -@+                 @+							\n";    Sleep(75);              
       
	Sleep(2000);
                                                                                                                                                   
	system("CLS");
	pelea();
}

