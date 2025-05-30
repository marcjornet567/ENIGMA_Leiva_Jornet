#include "const.h"


void rotar(string& rotor) {
    char primerCaracter = rotor[0];
    for (int i = 0; i < rotor.length() - 1; ++i) {
        rotor[i] = rotor[i + 1];
    }
    rotor[rotor.length() - 1] = primerCaracter;
}

void xifrarMissatge(const string& mensajeOriginal, string rotor1, string rotor2, string rotor3,
    const string& notch1, const string& notch2, const string& notch3) {

    string mensajeCifrado;

    for (char caracter : mensajeOriginal) {
        if (caracter == ' ') continue;

        // Pasar por los rotores
        char paso1 = rotor1[caracter - 'A'];
        char paso2 = rotor2[paso1 - 'A'];
        char paso3 = rotor3[paso2 - 'A'];
        mensajeCifrado += paso3;

        // Rotar rotores
        rotar(rotor1);

        if (rotor1[0] == notch1[0]) {
            rotar(rotor2);
        }
        if (rotor2[0] == notch2[0]) {
            rotar(rotor3);
        }
    }

    cout << "Missatge xifrat: " << mensajeCifrado << endl;

    ofstream archivoSalida("MissatgeXifrat.txt");
    archivoSalida << mensajeCifrado << endl;
    archivoSalida.close();
}