#pragma once
#include <string>
#include <iostream>
#include "Structs.h"
#include "Carpetas.h"
using namespace std;
/*volumen*/
void crearVolumen(string nombre, int numberOfblocs, int  blocSize);
int referenciaDeGuardado();
int guardarEnVolumen(string str);
void guardarEnBloc(string str, int padre, int referencia);
void borrarVolumen(struct volumen* vol);
void imprimirVolumen(int stop);
string leerVolumen(int posicion);

//variables
struct volumen* vol;
string nombreDelVolumen;
int maxOfblocs = 0;
int sizeOfBloc = 0;

void crearVolumen(string nombre, int blocs, int size) {

    vol = new struct volumen[blocs];
    for (int i = 0; i < blocs; i++)
    {
        vol[i].data = new char[size];
    }

    if (vol == NULL) {
        cout << "dude new es hermoso" << endl;
        delete[] vol;
    }
    maxOfblocs = blocs;
    sizeOfBloc = size;
    nombreDelVolumen = nombre;
    carpetaActual = crearCarpetaInicial("");
}

void guardarEnBloc(string str, int padre, int referencia) {
    if (sizeOfBloc == 0 || maxOfblocs == 0) {
        cout << "El volumen no ha sido inicializado" << endl;
        return;
    }

    string residuo = "";
    if (str.size() > sizeOfBloc) {
        residuo = str.substr(sizeOfBloc, str.size());
        str = str.substr(0, sizeOfBloc);
    }

    for (int i = referencia; i < maxOfblocs; i++) {

        if (vol[i].usado == true) continue;
        for (int j = 0; j < str.size(); j++) {
            vol[i].data[j] = str[j];
        }
        vol[i].usado = true;
        vol[i].cantidad = str.size();
        if (residuo.size() > 0) {
            guardarEnBloc(residuo, i, i);
        }

        if (padre >= 0) {
            vol[padre].hijo = i;
        }

        break;
    }

}

string leerVolumen(int posicion) {
    string data = "";
    while (posicion != -1){
    
        for (int i = 0; i < vol[posicion].cantidad && i < sizeOfBloc; i++) {

           data += vol[posicion].data[i];

        }

        posicion = vol[posicion].hijo;

    };

    return data;
}

void borrarBloc(int posicion) {


    while (posicion != -1) {

        for (int i = 0; i < vol[posicion].cantidad && i < sizeOfBloc; i++) {

            vol[posicion].data[i] = '-';

        }
        vol[posicion].usado = false;
        vol[posicion].cantidad = -1;
        posicion = vol[posicion].hijo;
        vol[posicion].hijo = -1;
    };


}

int guardarEnVolumen(string str) {

    if (sizeOfBloc == 0 || maxOfblocs == 0) return -1;
    int ref = referenciaDeGuardado();
    guardarEnBloc(str, -1, ref);
    return ref;

}

int referenciaDeGuardado() {
    for (int i = 0; i < maxOfblocs; i++) {
        if (vol[i].usado == false) return i;
    }
}

void borrarVolumen(struct volumen* vol) {
    if (vol != NULL) {
        delete[] vol;
    }
}

void imprimirVolumen(int stop) {

    for (int i = 0; i < maxOfblocs; i++)
    {
        cout << "el volumen: " << i << endl;
        cout << "data: " << vol[i].data << endl;
        cout << "hijo: " << vol[i].hijo << endl;
        cout << "usado: " << vol[i].usado << endl;
        if (i == stop + 1)break;
        cout << endl;
    }

}