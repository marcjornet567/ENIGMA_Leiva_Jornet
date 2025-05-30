#include "const.h"
#include "xifratge.h"
#include "utils.h"


void parsear_Rotor(string& texto1, string& notch1, string& texto2, string& notch2, string& texto3, string& notch3) {
    
    ifstream rotorFile1("rotor1.txt");
    getline(rotorFile1, texto1);

    if (getline(rotorFile1, notch1)) {
        notch1 = notch1[0];
    }
    else {
        notch1 = 'Z';
    }

    rotorFile1.close();


    ifstream rotorFile2("rotor2.txt");

    getline(rotorFile2, texto2);

    if (getline(rotorFile2, notch2)) {
        notch2 = notch2[0];
    }
    else {
        notch2 = 'Z';
    }

    rotorFile2.close();

 
    ifstream rotorFile3("rotor3.txt");
    getline(rotorFile3, texto3);

    if (getline(rotorFile3, notch3)) {
        notch3 = notch3[0];
    }
    else {
        notch3 = 'Z';
    }

    rotorFile3.close();
}





int main() {

    string texto1;
    string notch1;

    string texto2;
    string notch2;

    string texto3;
    string notch3;

    //Funcio per cridar a el parseo de rotors a strings
    parsear_Rotor(texto1, notch1, texto2, notch2, texto3, notch3);


	// Variables per guardar el resultat del input del usuari
    int opcioMenu;

    cout << "\tEnigma" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Xifrar missatges" << endl;
    cout << "2. Desxifrar missatges" << endl;
    cout << "3. Editar rotors" << endl;
    cout << "4. Sortir" << endl;
    cin >> opcioMenu;
    cin.get(); // per netejar el buffer d'entrada despres del cin, que si no, el getline no funcionaria correctament

    roto1.open("rotor1.txt");
    roto1 << "MBRPJLZFOVNCKQDEWAGUTXHYS\nI" << endl;
    roto1.close();

    roto2.open("rotor2.txt");
    roto2 << "XHSGMLDYNVBOIWZCAFJPRQKUE\nT" << endl;
    roto2.close();

    roto3.open("rotor3.txt");
    roto3 << "TUDCSMHFALIPEWJYZNGOQBKRV\nX" << endl;
    roto3.close();


    switch (opcioMenu) {
    case 1:
        cout << "Xifrar missatges" << endl;
        cout << "Escriu el missatge a xifrar: ";
        getline(cin, missatge); // captura espais en el missatge

        for (int i = 0; i < missatge.length(); i++) {
            // Si es lletra minuscula, convertir a majuscula
            if (missatge[i] >= 'a' && missatge[i] <= 'z') {
                missatge[i] -= 32;
            }
            // Si es majuscula o espai, aceptar
            else if ((missatge[i] >= 'A' && missatge[i] <= 'Z') || missatge[i] == ' ') {
                // No fer res
            }
            // Altres caracters
            else {
                cout << "Caracter no permes: " << missatge[i] << endl;
                return 1; // Acaba el programa si hi ha un caracter no permes
            }
        }

        // ELIMINAR ELS ESPAIS EN BLANC
        for (int i = 0; i < missatge.length(); i++) {
            if (missatge[i] != ' ') {
                resultado += missatge[i]; // Afegir nomes els caracters que no siguin espais
            }
        }

        // AGRUPAR EL MISSATGE EN GRUPS DE 5 CARACTERES
        for (int i = 5; i < resultado.length(); i += 6) {
            resultado.insert(i, " "); // Insertar un espai cada 5 caracters
        }

        cout << "El missatge a xifrar es: " << resultado << endl;

        // Guardar el missatge normal en un fitxer  
        missatge_base.open("Missatge.txt");
        missatge_base << resultado << endl; // Guardar el mensaje en el archivo
        missatge_base.close();


		//Funcio que crida a la funcio de xifratge, que ara ja podem enviarli strings i no ofstream
        xifrarMissatge(resultado, texto1, texto2, texto3, notch1, notch2, notch3);



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
        cout << "Opció no vàlida" << endl;
        break;
    }
}