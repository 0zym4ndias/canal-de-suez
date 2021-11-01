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
    int fechaInt;
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
    int mesInt;
};

//#include "LinkedList.h"
//#include "LinkedList.h"
#include "LinkedLis.h"


// * Funcion que sobrecarga el operator <<
ostream &operator<<(ostream &os, const registro &otra)
{
    // Instrucciones
    os << otra.ubi << " " << otra.fecha << " " << otra.mes << " " << otra.year << " " << otra.hora << " " << otra.entrada << endl;
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

vector<registroVect> finalRegister(vector<registroVect> vec1, vector<registroVect> vec2)
{

    vector<registroVect> vectorFinal;
    int i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size())
    {
        registroVect fin;

        if (vec1[i].mesInt < vec2[j].mesInt)
        {
            cout << "mes < mes" << endl;
            fin.mes = vec1[i].mes;
            fin.year = vec1[i].year;
            fin.cantMed = vec1[i].cantMed;
            fin.cantRoj = vec1[i].cantRoj;
            i++;
        }
        else if(vec1[i].mesInt > vec2[j].mesInt)
        {
            cout << "mes > mes" << endl;
            fin.mes = vec2[j].mes;
            fin.year = vec2[j].year;
            fin.cantMed = vec2[j].cantMed;
            fin.cantRoj = vec2[j].cantRoj;
            //vectorFinal.push_back(fin);
            j++;
        }
        else{
            fin.mes = vec1[i].mes;
            fin.year = vec1[i].year;
            fin.cantMed = vec1[i].cantMed + vec2[j].cantMed;
            fin.cantRoj = vec1[i].cantRoj + vec2[j].cantRoj;
            //vectorFinal.push_back(fin);
            i++;
            j++;
        }
        vectorFinal.push_back(fin);
    }
    registroVect fin;
    while (i < vec1.size())
    {
        
        fin.mes = vec1[i].mes;
        fin.year = vec1[i].year;
        fin.cantMed = vec1[i].cantMed + vec2[i].cantMed;
        fin.cantRoj = vec1[i].cantRoj + vec2[i].cantRoj;
        vectorFinal.push_back(fin);
        i++;
    }
    
    while (j < vec2.size())
    {
        registroVect fin;
        fin.mes = vec2[i].mes;
        fin.year = vec2[i].year;
        fin.cantMed = vec2[j].cantMed + vec2[j].cantMed;
        fin.cantRoj = vec2[j].cantRoj + vec2[j].cantRoj;
        vectorFinal.push_back(fin);
        i++;
    }
    //vectorFinal.push_back(fin);
    return vectorFinal;
}

int main()
{

    system("cls"); // * Limpiar la terminal

    string date, hour, ub, nomArch;
    int dateInt;
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
        registro.fechaInt = ftoi(date);

        if (registro.entrada == 'M')
        {

            buquesM.addLast(registro);
        }
        else
        {
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

    //buquesR.print();
    //buquesM.print();
    vector<registroVect> vec1 = buquesM.busqueda(serieSearch);

    cout << "----------------------------Mediterraneo-------------------" << endl;
    if(vec1.size() > 0){
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i].mes << " " << vec1[i].year << " " << vec1[i].cantMed << " " << vec1[i].cantRoj /*<< " " << vec1[i].mesInt */<< endl;
    }
    }
    vector<registroVect> vec2 = buquesR.busqueda(serieSearch);

    cout << "----------------------------Rojo-------------------" << endl;
    if(vec2.size() > 0){
    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i].mes << " " << vec2[i].year << " " << vec2[i].cantMed << " " << vec2[i].cantRoj /*<< " " << vec2[i].mesInt */<< endl;
    }
    }
    cout << "----------------------------Final-------------------" << endl;
    
    vector<registroVect> vectF = finalRegister(vec1, vec2);

    for (int i = 0; i < vectF.size(); i++)
    {
        cout << vectF[i].mes << " " << vectF[i].year << " " << vectF[i].cantMed << " " << vectF[i].cantRoj << endl;
    }
    /*
    string meses[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug","sep", "oct", "nov", "dic"};
    vector<registroVect> vectF;
    int maxsi = max(vec1.size(),vec2.size());
    int mins = min(vec1.size(),vec2.size());
    int size = maxsi - mins;

    for(int i = 0; i < size; i++){
        if((meses[i] == vec1[i].mes) || (meses[i] == vec2[i].mes)){
            
            registroVect finalReg;
            finalReg.mes = meses[i];
            finalReg.year = vec1[i].year;
            finalReg.cantMed = vec1[i].cantMed + vec2[i].cantMed;
            finalReg.cantRoj = vec1[i].cantRoj + vec2[i].cantRoj;
            
            vectF.push_back(finalReg);
        }
    }

    cout << "----------------------------Vect F-------------------" << endl;


    for (int i = 0; i < vectF.size(); i++)
    {
        cout << vectF[i].mes << " " << vectF[i].year << " " << vectF[i].cantMed << " " << vectF[i].cantRoj << endl;
    }
    */
}

/*
    
    LinkedList<registro> buquesT(buquesR);
    buquesT += buquesM;
    buquesT.sort();

    vector<registroVect> vectorFin = buquesT.busqueda(serieSearch);

    for (int i = 0; i < vectorFin.size(); i++)
    {
        cout << vectorFin[i].mes << " " << vectorFin[i].year << " " << vectorFin[i].cantMed << " " << vectorFin[i].cantRoj << endl;
    }
    
}
*/