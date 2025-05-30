#include "const.h"


void rotar(string& rotor) {
	char primerCaracter = rotor[0]; //guardem el primer caracter del rotor a la vcariable primerCaracter, per ficarlo dsp a darrera de la string del rotor
    for (int i = 0; i < rotor.length() - 1; ++i) {
		rotor[i] = rotor[i + 1]; // avançar tots els caracters del rotor una posició cap a l'esquerra   
    }
	rotor[rotor.length() - 1] = primerCaracter; // coloquem el primer caracter al final del rotor
}