/*
Nombre: Eduardo Loya Montes de Oca - A01383049
Nombre: Roberto Abraham Perez Iga - A01384237
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 04 de Septiembre del 2021

Ultima Versión: 

Descripción: El canal de Suez es un canal navegable que conecta el mar 
Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por 
un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en 
el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente.

Objetivos:
1. Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en un vector.
2. Ordene la información por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).
3. Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
4. Despliegue todas las entradas al canal de los buques de esas series en forma ordenada UBI+Fecha.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// * Struct para el vector que guardara el .txt file
struct registro
{
    string fecha;
    string mes;
    string year;
    string hora;
    char entrada;
    string ubi;
    string tripcar;
    int fechaInt;
    int mesInt;
    int size;
    bool operator>(const registro &otro) const
    {
        if (this->ubi == otro.ubi)
        {
            return this->fechaInt > otro.fechaInt;
        }
        return (this->ubi.compare(otro.ubi) > 0); // * Cuidado como compara 2 strings
    }

    string ubisub(int i)
    {
        string ubic = ubi.substr(0, i);
        return ubic;
    }

    friend ostream &operator<<(ostream &os, const registro &otra);
};

struct registroVect
{
    string mes;
    string year;
    int cantMed;
    int cantRoj;
};

#include "LinkedList.h"

// * Funcion que sobrecarga el operator <<
ostream &operator<<(ostream &os, const registro &otra)
{
    // Instrucciones
    os << otra.tripcar << " " << otra.ubi << " " << otra.fecha << " " << otra.mes << " " << otra.year << " " << otra.hora << " " << otra.entrada << " " << otra.mesInt << endl;
    return os;
}

// * Funcion que transforma un mes a INT
// ? Complejidad: O(1)
int mestoi(string m)
{

    if (m == "jan")
    {

        return 1;
    }
    if (m == "feb")
    {

        return 2;
    }
    if (m == "mar")
    {

        return 3;
    }
    if (m == "apr")
    {

        return 4;
    }
    if (m == "may")
    {

        return 5;
    }
    if (m == "jun")
    {

        return 6;
    }
    if (m == "jul")
    {

        return 7;
    }
    if (m == "aug")
    {

        return 8;
    }
    if (m == "sep")
    {

        return 9;
    }
    if (m == "oct")
    {

        return 10;
    }
    if (m == "nov")
    {

        return 11;
    }
    return 12;
}

// * Funcion que transforma una fecha string a INT
// ? Complejidad: O(n)
int ftoi(string fecha)
{

    int salida = 0;
    int aux = 0;
    int i = 0;

    while (fecha[i] != '-')
    {

        aux *= 10;
        aux += (fecha[i] - '0'); // * '5' -'0' == 5 como entero (53-48)
        i++;
    }

    salida += aux;
    i++;
    string mes = "";

    while (fecha[i] != '-')
    {

        mes += fecha[i];
        i++;
    }

    salida += (mestoi(mes) * 100);
    aux = 0;
    i++;

    while (i < fecha.length())
    {

        aux *= 10;
        aux += (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
        i++;
    }

    salida += (aux * 10000);
    return salida;
}

/*
vector<registroVect>finalRegister(LinkedList<registro> listaM, LinkedList<registro> listaR, string ubi){

    if(listaM.getSize() > 0 && listaR.getSize() > 0)
    {
        
        
        vector<registroVect> vectorFinal;
        int i=0, j=0;
    }

    else{
        cout << "Vacias" << endl;
    }

}
*/

int main()
{

    //system("cls"); // * Limpiar la terminal

    string date, hour, ub, nomArch;
    int dateInt, sizeM = 0, sizeR = 0;
    char entryDate;
/*
    cout << "Archivo -> ";
    cin >> nomArch;
    cout << endl;

    while (nomArch != "suez.txt")
    {

        cout << "Favor de insertar archivo suez.txt -> ";
        cin >> nomArch;
        cout << endl;
    }
*/
    ifstream datosSuez;
    datosSuez.open("suez.txt");

    LinkedList<registro> buquesM;
    LinkedList<registro> buquesR;

    while (datosSuez >> date >> hour >> entryDate >> ub)
    {
        registro registro;
        int idx = date.find("-");

        registro.fecha = date;
        registro.mes = date.substr(idx + 1, 3);
        registro.year = date.substr(idx + 5, 2);
        registro.hora = hour;
        registro.entrada = entryDate;
        registro.ubi = ub;
        registro.tripcar = ub.substr(0,3);
        registro.fechaInt = ftoi(date);
        registro.mesInt = mestoi(date.substr(idx + 1, 3));

        if (registro.entrada == 'M')
        {
            sizeM++;
            registro.size = sizeM;
            buquesM.addLast(registro);
        }
        else
        {
            sizeR++;
            registro.size = sizeR;
            buquesR.addLast(registro);
        }
    }

    datosSuez.close();

    cout << "Ordenando Datos..." << endl;
    cout << endl;

    buquesM.sort();
    buquesR.sort();
    /*
    string archSalida;
    cout << "Nombre de archivo de salida para buques del Mar Mediterraneo -> ";
    cin >> archSalida;
    buquesM.fileout(archSalida);

    cout << "Nombre de archivo de salida para buques del Mar Rojo -> ";
    cin >> archSalida;
    buquesR.fileout(archSalida);
*/
    // en el cuarto se puede usar vector
    string serieSearch;

    cout << "Serie a buscar -> ";
    cin >> serieSearch;

cout << "----------------------------Mediterraneo-------------------" << endl;
    vector<registroVect> vec1 = buquesM.busqueda(serieSearch);

    
    
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i].mes << " " << vec1[i].year << " " << vec1[i].cantMed << " " << vec1[i].cantRoj /*<< " " << vec1[i].mesInt */<< endl;
    }
    
    cout << "----------------------------Rojo-------------------" << endl;
    vector<registroVect> vec2 = buquesR.busqueda2(serieSearch);

    
    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i].mes << " " << vec2[i].year << " " << vec2[i].cantMed << " " << vec2[i].cantRoj /*<< " " << vec2[i].mesInt */<< endl;
    }
    
    
}
