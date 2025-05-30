#include "const.h"
#include "rotar.h"


// Retorna la lletra original buscant en el rotor inversament
char inversoRotor(const string& rotor, char letra) {
    for (int i = 0; i < rotor.size(); ++i) {
        if (rotor[i] == letra) {
            return 'A' + i;
        }
    }
    return letra; // En caso de error
}

// Función para descifrar un mensaje
void desxifrarMissatge(const string& mensajeCifrado, string rotor1, string rotor2, string rotor3,
    const string& notch1, const string& notch2, const string& notch3) {

    string mensajeDescifrado;

    for (size_t i = 0; i < mensajeCifrado.length(); ++i) {
        char caracter = mensajeCifrado[i];
        if (caracter == ' ') continue;

        // Paso inverso por rotores (de atrás hacia adelante)
        char paso1 = inversoRotor(rotor3, caracter);
        char paso2 = inversoRotor(rotor2, paso1);
        char paso3 = inversoRotor(rotor1, paso2);

        mensajeDescifrado += paso3;

        // Rotaciones (idénticas al cifrado)
        rotar(rotor1);
        if (rotor1[0] == notch1[0]) {
            rotar(rotor2);
        }
        if (rotor2[0] == notch2[0]) {
            rotar(rotor3);
        }
    }

    cout << "Missatge desxifrat: " << mensajeDescifrado << endl;

    ofstream archivoSortida("MissatgeDesxifrat.txt");
    archivoSortida << mensajeDescifrado << endl;
    archivoSortida.close();
}