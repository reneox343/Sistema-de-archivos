#pragma once
#include "ManupulacionDeString.h"
#include "Volumen.h"
#include <sstream>
#include <string>
#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

string getFileData(string fileName);
void subirArchivo(string fileName, string nuevoNombre);
void borrarArchivo(struct archivo* archivo);
void descargarArchivo(string fileName, string nuevoNombre);
struct archivo obtenerArchivo(string nombre);

string getFileData(string fileName) {
    ifstream f("../archivos/"+fileName); 
    string str;
    //leer string de archivo
    if (f) {
        ostringstream ss;
        ss << f.rdbuf();
        str = ss.str();
    }
    return str;
}

void descargarArchivo(string fileName,string nuevoNombre) {
    struct archivo archivoEncontrado = obtenerArchivo(fileName);
    if (archivoEncontrado.extencion == -1 || archivoEncontrado.nombre == -1 || archivoEncontrado.referencia == -1) {
        borrarArchivo(&archivoEncontrado);
        return;
    }
    ofstream file;
    file.open("../descargas/" + nuevoNombre + leerVolumen(archivoEncontrado.extencion), fstream::out);
    file << leerVolumen(archivoEncontrado.referencia);
    file.close();
}

void subirArchivo(string fileName,string nuevoNombre) {
    struct archivo* nuevoArchivo = new struct archivo;
    nuevoArchivo->nombre = guardarEnVolumen(nuevoNombre);
    nuevoArchivo->referencia = guardarEnVolumen(getFileData(fileName));
    nuevoArchivo->extencion = guardarEnVolumen('.' + splitString(fileName, '.', 2));
    carpetaActual->archivos.push_back(*nuevoArchivo);
}

struct archivo obtenerArchivo(string fileName) {
    for (auto& item : carpetaActual->archivos) {
        if (fileName == leerVolumen(item.nombre) + leerVolumen(item.extencion)) return item;
    }
    struct archivo* nuevoArchivo = new struct archivo;
    return *nuevoArchivo;
}

void borrarArchivo(struct archivo* archivo) {
    if (archivo != NULL) {
        delete[] archivo;
    }
}