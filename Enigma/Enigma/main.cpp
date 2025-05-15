#include "const.h"

int main() {
	short opcioMenu;
	string missatge; 

	cout << "\tEnigma" << endl;
	cout << "-----------------------" << endl;
	cout << "1. Xifrar missatges" << endl;
	cout << "2. Desxifrar missatges" << endl;
	cout << "3. Editar rotors" << endl;
	cout << "4. Sortir" << endl;
	cin >> opcioMenu;

	ofstream roto1;
	ofstream roto2;
	ofstream roto3;

	roto1.open("rotor1.txt");
	roto1 << "MBRPJLZFOVNCKQDEWAGUTXHYS\nI" << endl;
	roto1.close();

	roto2.open("rotor2.txt");
	roto2 << "XHSGMLDYNVBOIWZCAFJPRQKUE\nT" << endl;
	roto2.close();

	roto3.open("rotor3.txt");
	roto3 << "TUDCSMHFALIPEWJYZNGOQBKRV\nX" << endl;
	roto2.close();

	// Opcion 1: Xifrar missatges
	switch (opcioMenu)
	{
	case 1:
		cout << "Xifrar missatges" << endl;

		cout << "Escriu el missatge a xifrar: ";
		cin >> missatge; 

		
		for (int i = 0; i < missatge.length(); i++) {
			if (missatge[i] >= 65 && missatge[i] <= 90) {
			}
			else if (missatge[i] >= 97 && missatge[i] <= 122) { 
				missatge[i] -= 32;
			}
			else if (missatge[i] == 32) {
				missatge[i] = ' '; 
			}
			else {
				cout << "El caracter introducido no es una letra aceptable" << endl;
				break;
			}
		}

		// aqui hay que pasar el mensaje al archivo con getline para que pille los espacios

		break;
	case 2: 
		cout << "Desxifrar missatges" << endl;
		break;
	case 3:
		cout << "Editar rotors" << endl;
		break;
	case 4:
		cout << "Sortir" << endl;
		break;

	default:
		break;
	}
	
}