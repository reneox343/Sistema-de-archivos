// Sistema de archivos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//librerias
#include<iostream>
#include<string>
#include <bitset>
#include <set>
#include<sstream>
//encabezados
#include "Structs.h"
#include "ManupulacionDeString.h"
#include "Volumen.h"
#include "Archivos.h"
//#include "Carpetas.h"
using namespace std;
//funciones
bool stringContains(string palabra, char caracter);
string splitString(string str, char caracter, int pos);
void ls();
void menu(string opc);

int main()
{


    /*volumen*/
    crearVolumen("hola",10,4);
    //int popis = guardarEnVolumen("popi");
    //cout << "ref" << guardarEnVolumen("reneastirola") <<endl;
    //cout <<"posicion de la carpeta: " << carpetaActual->nombre<<endl;
    //cout <<"nombre de la carpeta: " << leerVolumen(carpetaActual->nombre)<<endl;
    //cout <<"posicion de popis: " << popis <<endl;
    //cout <<"nombre de popis: " << leerVolumen(popis)<<endl;
    //borrarBloc(popis);
    //imprimirVolumen(5);
    //borrarVolumen(vol);

    /*con archivos*/
    crearVolumen("hola",100,100);
    
    subirArchivo("rojo.png","rojoD");
    //imprimirVolumen(6);
    //descargarArchivo("rojoD.txt", "rojoD");
    ls();
    borrarVolumen(vol);

    /*menu*/
    //string opc;
    //do {
    //    cout << ">> ";
    //    getline(cin, opc);
    //    cout << endl;
    //    menu(opc);

    //} while (true);

}

void menu(string opc){

    if (stringContains(opc,' ')) {

        string subopc = opc.substr(0, opc.find(" "));
        if (subopc == "create")
        {

            string nombre = splitString(opc, ' ', 2);
            stringstream size(splitString(opc, ' ', 3));
            stringstream bloc(splitString(opc, ' ', 4));
            int blocSize;
            int numberOfBlocs;
            size >> blocSize;
            bloc >> numberOfBlocs;
            crearVolumen(nombre,blocSize,numberOfBlocs);
            
        ;} 
        else if (subopc == "mount") {
            string nombre = splitString(opc, ' ', 2);
            

        }
        else if (subopc == "load") {
            string nombreOriginal = splitString(opc,' ', 2);
            string copia = splitString(opc, ' ', 3);
            subirArchivo(nombreOriginal, copia);

        }
        else if (subopc == "download") {
            string archivo = splitString(opc, ' ', 2);
            string copia = splitString(opc, ' ', 3);
            descargarArchivo(archivo, copia);

        }
        else if (subopc == "rm") {
            string directorio = splitString(opc, ' ', 2);

        }
        else if (subopc == "details") {
            string archivo = splitString(opc, ' ', 2);

        }
        else if (subopc == "mkdir") {
            string dirname = splitString(opc, ' ', 2);
            crearCarpeta(dirname);
        }
        else if (subopc == "cd") {
            string directorio = splitString(opc, ' ', 2);

        }
    }
    else {

        if (opc  == "unmount") {

        }
        else if (opc == "ls") {
            ls();
        }
        else if (opc == "info") {

        }
        else if (opc == "pwd") {

        }
    
    }

}


void ls() {

    for (auto& item : carpetaActual->archivos) {
        cout <<"\t"<< leerVolumen(item.nombre) << leerVolumen(item.extencion) << endl;

    }

    for (auto& item : carpetaActual->hijos) {
        cout<<"\t" << leerVolumen(item.nombre) << endl;
    }

}

