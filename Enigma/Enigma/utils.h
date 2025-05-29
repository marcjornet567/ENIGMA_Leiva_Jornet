#pragma once

short opcioMenu;
string missatge;

ofstream roto1;
ofstream roto2;
ofstream roto3;
//de ofstream a string per poder fer servir les funcions de string
//string roto1_str;
string roto1_str;
string roto2_str;
string roto3_str;

ofstream missatge_base;


//Sacar los notch al final de cada rotor
//version hardcodeada

//char notchrot1 = 'I';
//char notchrot2 = 'T';
//char notchrot3 = 'X';
//version no HARDCOEDADA
//usar .eof(), mira si es final archivo

// Variable resultat fora del switch.
string resultado;