#include "const.h"

int main() {
	short opcioMenu;

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

	// Opcion 1: Xifrar missatges
	switch (opcioMenu)
	{
	case 1:
		cout << "Xifrar missatges" << endl;
		roto1.open("rotor1.txt");
		roto1 << "MBRPJLZFOVNCKQDEWAGUTXHYSI" << endl;
		roto1.close();
	
		roto2.open("rotor2.txt");
		roto2 << "XHSGMLDYNVBOIWZCAFJPRQKUET" << endl;
		roto2.close();

		roto3.open("rotor3.txt");
		roto3 << "TUDCSMHFALIPEWJYZNGOQBKRVX" << endl;
		roto2.close();

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