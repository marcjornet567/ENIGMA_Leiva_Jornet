#include "const.h"


void rotar(string& rotor) {
    char primerCaracter = rotor[0];
    for (int i = 0; i < rotor.length() - 1; ++i) {
        rotor[i] = rotor[i + 1];
    }
    rotor[rotor.length() - 1] = primerCaracter;
}