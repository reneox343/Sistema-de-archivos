#pragma once
#include<string>
using namespace std;
bool stringContains(string str, char caracter) {
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == caracter) return true;
    }
    return false;
}

int stringRepeats(string str, char caracter) {
    int cont = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == caracter)cont++;
    }
    return cont;
}

string splitString(string str, char caracter, int pos) {
    string resultado = "";
    int cont = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == caracter) {
            cont++;
            if (cont == pos) return resultado;
            resultado = "";
        }
        if (str[i] != caracter)resultado += str[i];
    }
    if (cont == 0)return"";
    return resultado;
}

string splitString(string str, int subsplits, int pos) {
    string resultado = "";
    int cont = 0;
    for (int i = 0; i < str.size(); i++)
    {

        if (cont == subsplits) {
            cont = 0;
            if (cont == pos) return resultado;
            return resultado;
        }
        cont++;
        cont++;
        resultado += str[i];

    }
    return resultado;
}