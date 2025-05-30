#include "const.h"

ofstream xifrat;
//Xifrar missatge rebut per l'usuari utilitzant els rotors
void xifrarMissatge(string& resultado, string& roto1, string& roto2, string& roto3, string notch1, string notch2, string notch3) {

	//VARIABLE QUE GUARDARA EL MISSATGE CIFRAT
	string mensajeCifrado = "";

	// Xifrtage tenint en compte rotors y notchs
	for (int i = 0; i < resultado.length(); i++)
	{
		//ROTO 1
		
		//COMPROVACIO DE SI EL ROTOR1 ESTA EN EL NOTCH
		if (roto1[0] == notch1[0]) {
			//La lletra es del torn del roto1 i la lletra notch son iguals
			//El Roto2 haura d'avancar una posicio
			//	Movemos el rotor2 una posicio
			char primerCaracterRot2 = roto2[0]; // Guardamos el primer caracter

			for (int i = 0; i < roto2.size() - 1; ++i) {
				roto2[i] = roto2[i + 1]; // Mueve cada elemento una posici�n a la izquierda
			}

			roto2[roto2.size() - 1] = primerCaracterRot2; // Mueve el primer caracter al final
			cout << endl << roto2 << endl;
		}	

		

		//ROTO 2

		//COMPROVACIO DE SI EL ROTOR2 ESTA EN EL NOTCH
		if (roto2[0] == notch2[0]) {
			//La lletra es del torn del roto2 i la lletra notch son iguals
			//El Roto3 haura d'avancar una posicio
			//	Movemos el rotor3 una posicio
			char primerCaracterRot3 = roto3[0]; // Guardamos el primer caracter

			for (int i = 0; i < roto3.size() - 1; ++i) {
				roto3[i] = roto3[i + 1]; // Mueve cada elemento una posici�n a la izquierda
			}

			roto3[roto3.size() - 1] = primerCaracterRot3; // Mueve el primer caracter al final
			cout << endl << roto3 << endl;
		}

		

		// ROTO 3

		//COMPROVACIO DE SI EL ROTOR3 ESTA EN EL NOTCH
		if (roto3[0] == notch3[0]) {
			//La lletra es del torn del roto3 i la lletra notch son iguals
			//El Roto1 haura d'avancar una posicio
			//	Movemos el rotor1 una posicio
			char primerCaracterRot1 = roto1[0]; // Guardamos el primer car�cter

			for (int i = 0; i < roto1.size() - 1; ++i) {
				roto1[i] = roto1[i + 1]; // Mueve cada elemento una posici�n a la izquierda
			}

			roto1[roto1.size() - 1] = primerCaracterRot1; // Mueve el primer caracter al final
			cout << roto1 << endl;
			
		}

		// Cifrar la letra
		char letra = resultado[i];
		
		int index = letra - 'A'; // Convertir letra a �ndice (0-25)
		letra = roto1[index]; // Pasar por el rotor 1
		index = letra - 'A'; // Convertir de nuevo a �ndice
		letra = roto2[index]; // Pasar por el rotor 2
		index = letra - 'A'; // Convertir de nuevo a �ndice
		letra = roto3[index]; // Pasar por el rotor 3
		mensajeCifrado += letra; // Agregar letra cifrada al resultado
		
		


	}
	cout << "Mensaje: " << mensajeCifrado << endl;
}