#include "const.h"
#include "xifratge.h"
#include "utils.h"

int main() {

    cout << "\tEnigma" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Xifrar missatges" << endl;
    cout << "2. Desxifrar missatges" << endl;
    cout << "3. Editar rotors" << endl;
    cout << "4. Sortir" << endl;
    cin >> opcioMenu;
    cin.get(); // per netejar el buffer d'entrada despres del cin, que si no, el getline no funcionaria correctament
    
    //INTENTO DE
   
 //   fstream roto1;
 //   roto1.open("rotor1.txt");
 //   roto1 << "MBRPJLZFOVNCKQDEWAGUTXHYS\nI" << endl;
 //  
 //   if (!roto1.is_open())
	//{
	//	cout << "Error al obrir el fitxer rotor1.txt" << endl;
	//}
 //   else
 //   {
 //       string roto1_str;
 //       while(getline(roto1, roto1_str)); {

	//		cout << "VAINAAAAAAA LOCAACCCCACA" << roto1_str << endl; // Mostrar el contingut del rotor1
	//	}
	//	roto1.close();
 //   }

   
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

        



		//Funcio de xifratge, ES NECESARIO QUE roto1, roto2, roto3 siguin strings i no ofstream, los notch, dejalos en chars
        xifrarMissatge(resultado, roto1, roto2, roto3, notchrot1, notchrot2, notchrot3);

		

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