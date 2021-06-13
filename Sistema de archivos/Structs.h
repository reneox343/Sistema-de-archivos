#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct usuario{
	long int nombre;
	long int carpeta;
};

struct carpeta {
	long int padres;
	vector<long int> hijos;
	vector<long int> archivos;
};

struct metadatos{
	long int permisos;
	long int fecha;
	int fileSize;
	long int data;
};

struct archivos {
	//si se completa a escribir en un bloc en caso de que no poner null y --->
	long int data;
	//si no se completa a escribir en un bloc contiene otras referencias
	vector<long int> hijos;
};

struct volumen
{
	long int* blocs;
	char* data;
	bool usado = false;
};