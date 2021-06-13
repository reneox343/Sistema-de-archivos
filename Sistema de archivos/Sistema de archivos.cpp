// Sistema de archivos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//librerias
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <bitset>
#include <set>
//encabezados
#include "Structs.h"
#include "ManupulacionDeString.h"

using namespace std;
//funciones
string getFileBits(string fileName);
bool stringContains(string palabra, char caracter);
string splitString(string str, char caracter, int pos);
void menu(string opc);
void crearVolumen(string nombre, int numberOfblocs, int  blocSize);
int guardarEnVolumen(string str);
void deleteVolumen(struct volumen* vol);
//variables
struct volumen* vol;
string nombreDelVOlumen;
int numberOfbloc = 0;
int sizeOfBloc = 0;

int main()
{
    crearVolumen("hola",3,3);
    guardarEnVolumen("hola");
    deleteVolumen(vol);
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
            string originalname = splitString(opc,' ', 2);
            string copia = splitString(opc, ' ', 3);

        }
        else if (subopc == "download") {
            string archivo = splitString(opc, ' ', 2);
            string copia = splitString(opc, ' ', 3);
        }
        else if (subopc == "rm") {
            string directorio = splitString(opc, ' ', 2);

        }
        else if (subopc == "details") {
            string archivo = splitString(opc, ' ', 2);

        }
        else if (subopc == "mkdir") {
            string dirname = splitString(opc, ' ', 2);

        }
        else if (subopc == "cd") {
            string directorio = splitString(opc, ' ', 2);
        }
    }
    else {

        if (opc  == "unmount") {

        }
        else if (opc == "ls") {

        }
        else if (opc == "info") {

        }
        else if (opc == "pwd") {

        }
    
    }

}

string getFileBits(string fileName){

    ifstream f("ejemplo.txt"); //taking file as inputstream
    string str;
    //leer string de archivo
    if (f) {
        ostringstream ss;
        ss << f.rdbuf();  
        str = ss.str();
    }
    return str;
}



void crearVolumen(string nombre, int blocs, int size) {

    vol = new struct volumen [blocs];
    for (int i = 0; i < blocs; i++)
    {
        vol[i].data = new char[size];
        vol[i].blocs = new long int[2];
    }
    
    if (vol == NULL) {
        cout << "dude new es hermoso" << endl;
        delete[] vol;
    }
    numberOfbloc = blocs;
    sizeOfBloc = size;
}

int guardarEnVolumen(string str) {
    if (sizeOfBloc == 0 || numberOfbloc == 0) {
        cout << "El volumen no ha sido inicializado"<<endl;
        return NULL;
    }
    if (str.size() <= sizeOfBloc) {
        for (size_t i = 0; i < numberOfbloc; i++)
        {
            if (vol[i].usado == true)continue;
            for (size_t j = 0; j < str.size(); j++)
            {
                vol[i].data[j] = str[j];
            }
            vol[i].usado = true;
            cout << vol[i].data <<endl;
            cout << "guardado"<<endl;
            return i;
        }

    }
    else {
        string substr = str.substr(0, sizeOfBloc);
        for (size_t i = 0; i < numberOfbloc; i++)
        {
            if (vol[i].usado == true)continue;
            for (size_t j = 0; j < substr.size(); j++)
            {
                vol[i].data[j] = substr[j];
            }
            vol[i].usado = true;
            cout << vol[i].data << endl;
            cout << "guardado" << endl;
            return i;
        }
        string residuo = str.substr(sizeOfBloc, str.size());
        //int substrPos = guardarEnVolumen(substr);

        cout << substr<<endl<<residuo<<endl;
    }

}
void deleteVolumen(struct volumen* vol) {    
        if (vol != NULL) {
            delete[] vol;
        }
    }

/*
void delVolumen(struct volumen* vol) {
    // Can safely assume vector is NULL or fully built.

    if (vol != NULL) {
        free(vol->data);
        free(vol);
    }
}
 */

/*
void crearVolumen(string nombre, int numberOfBlocs,int blocSize){

    vol = (struct volumen*)malloc(sizeof(struct volumen) * numberOfBlocs);
    if (vol == NULL)
        cout << "malloc me pega wey y no se por que" << endl;
    vol->data = (char*)malloc(blocSize * sizeof(char));
    if (vol->data == NULL) {
        free(vol);
        cout << "malloc malo" << endl;
    }
    vol->bloc = (long int*)malloc(blocSize * sizeof(long int));
    if (vol->bloc == NULL) {
        free(vol);
        cout << "malloc malo" << endl;
    }
    vol->nombre = -1;
    vol->usado = false;

}
*/


//memset deja que declares un arreglo con apuntador a caracter y deja en tienpo 
//de ejecucion que yo escoja el espacio de memoria (consejo de alcaraz)

