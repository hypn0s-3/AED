#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
class Archivo {
private:
	ofstream filewrite; //offstream escribe
	ifstream fileread; //ifstream lee
	string text;
	string cod_distrito, cod_partido, cant_votos;
public:
	Archivo() { }
	void readata() {
		fileread.open("votos.txt", ios::in);
		if (fileread.fail()) {
			fileread.close();
			filewrite.open("votos.txt", ios::out);
			filewrite << "U202215888 ";
			filewrite << "SI32 ";
			filewrite << "6 ";
			filewrite.close();
			fileread.open("votos.txt", ios::in);
		}
		fileread >> cod_distrito;
		fileread >> cod_partido;
		fileread >> cant_votos;
		fileread.close();
	}
	string getcod_distrito() { return cod_distrito; }
	string getcod_partido() { return cod_partido; }
	string getcant_votos() { return cant_votos; }

};