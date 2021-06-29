#include "Structs.h"
#include "Volumen.h"
using namespace std;

/*funciones*/
void crearCarpeta(string nombre);
struct carpeta* crearCarpetaInicial(string nombre);
//jaja no se por que no puedo quitar esta linea
int guardarEnVolumen(string str);
/*variables*/
struct carpeta* carpetaActual;

struct carpeta* crearCarpetaInicial(string nombre) {
    struct carpeta* nuevaCarpeta = new struct carpeta;
    nombre = "/" + nombre;
    nuevaCarpeta->nombre = guardarEnVolumen(nombre);
    return nuevaCarpeta;
}

void crearCarpeta(string nombre) {
    struct carpeta* nuevaCarpeta = new struct carpeta;
    nombre = "/" + nombre;
    nuevaCarpeta->nombre = guardarEnVolumen(nombre);
    carpetaActual->hijos.push_back(*nuevaCarpeta);
    nuevaCarpeta->padre = carpetaActual;
    carpetaActual = nuevaCarpeta;
}

void rm() {


};