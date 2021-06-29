#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct usuario{
	long int nombre;
	long int carpeta;
};

struct carpeta {
	int nombre;
	struct carpeta *padre;
	vector<struct carpeta> hijos;
	vector<struct archivo> archivos;
};


struct archivo {
	int nombre = -1;
	int extencion = -1;
	int referencia = -1;
	int fecha = -1;
	int fileSize = -1;
};

struct volumen
{
	long int hijo = -1;
	char* data;
	bool usado = false;
	int cantidad = -1;
};