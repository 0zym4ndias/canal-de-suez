/*

Nombre: Eduardo Loya Montes de Oca - A01383049
Nombre: Roberto Abraham Perez Iga - A01384237
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 04 de Septiembre del 2021

Ultima Versión:21 0ct 2021

SP: Canal de Suez con BST

Objetivos:
1. Solicite los nombre del archivo de entrada de cada uno de los mares (generados en la actividad 2.3) (Ej. canalM.txt y canalR.txt) 
y los abra, y contabilice las incidencias de cada una de las series (los primeros tres caracteres de el UBI) 
y almace como data único la UBI + Cantidad (donde cantidad es la llave del BST) en dos árboles binarios de búsqueda, 
uno para los que entran por el Mar Mediterráneo y otro para los buques que entran por el mar Rojo.

2. Despliegue en pantalla lo datos almacenados en en cada uno de los árboles en forma descendente,
 esto es la serie del buque que mas acceso tuvo.

*/


#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// * Struct para Nodo
struct registroNode{
    int cant;
    string ubi;

    registroNode(){
        cant = 0;
        ubi = "AAA";
    }
    
    registroNode(int cant, string ubi){
        this->cant = cant;
        this->ubi = ubi;
    }

    bool operator==(const registroNode &otra){

        return this->cant == otra.cant && this->ubi == otra.ubi;
    }

    bool operator>(const registroNode &otro){

        if (this->cant == otro.cant){

            return (this->ubi.compare(otro.ubi) < 0); // this -> nombre es mayor con negativo
        }
            return this->cant > otro.cant;
    }

    void operator=(const registroNode &otro){
        
        this->cant = otro.cant;
        this->ubi = otro.ubi;
    }

    friend ostream &operator<<(ostream &os, const registroNode &otra);
};

// * Funcion que sobrecarga el operator <<
ostream &operator<<(ostream &os, const registroNode &otra){
    // Instrucciones
    os << otra.ubi << " " << otra.cant;
    return os;
}

#include "BST.h"

int main(){

    //system("cls"); // * Limpiar la terminal

    string date, hour, ub, nomArchM, nomArchR;
    int dateInt;
    char entryDate;

    cout << "Archivo Mediterraneo -> ";
    cin >> nomArchM;
    cout << endl;

    while (nomArchM != "canalM.txt")
    {

        cout << "Favor de insertar archivo canalM.txt -> ";
        cin >> nomArchM;
        cout << endl;
    }

    ifstream datosSuezM;
    datosSuezM.open("canalM.txt");

    BST arbolM;
    int cantM = 0;
    string ubiTempM, ubiTempR;

    datosSuezM >> ub >> date >> hour >> entryDate;
    ubiTempM = ub.substr(0,3);
    cantM = 1;

    while (datosSuezM >> ub >> date >> hour >> entryDate){

        if(ubiTempM == ub.substr(0,3)){

            cantM +=1;
        }
        else{
            registroNode treeM;
            treeM.cant = cantM;
            treeM.ubi = ubiTempM;
            ubiTempM = ub.substr(0,3);
            arbolM.add(treeM);
            cantM = 1;
        }

    }
    registroNode treeM;
    treeM.cant = cantM;
    treeM.ubi = ubiTempM;
    arbolM.add(treeM);

    datosSuezM.close();
    
    cout << "Archivo Rojo -> ";
    cin >> nomArchR;

    while (nomArchR != "canalR.txt")
    {

        cout << "Favor de insertar archivo canalR.txt -> ";
        cin >> nomArchR;
        cout << endl;
    }

    ifstream datosSuezR;
    datosSuezR.open("canalR.txt");

    BST arbolR;
    int cantR = 0;
    
    datosSuezR >> ub >> date >> hour >> entryDate;
    ubiTempR = ub.substr(0,3);
    cantR = 1;

    while (datosSuezR >> ub >> date >> hour >> entryDate){

        if(ubiTempR == ub.substr(0,3)){

            cantR++;
        }
        else{
            registroNode treeR;
            treeR.cant = cantR;
            treeR.ubi = ubiTempR;
            ubiTempR = ub.substr(0,3);
            arbolR.add(treeR);
            cantR = 1;
        }
    }
    registroNode treeR;
    treeR.cant = cantR;
    treeR.ubi = ubiTempR;
    arbolR.add(treeR);

    datosSuezR.close();
    
    cout << endl;
    cout << "=== Entradas MarMediterraneo ===" << endl;
    
    //arbolM.print(1);
    //arbolM.print(2);
    //arbolM.print(3);
    //arbolM.print(4);
    arbolM.print(5);
    
    cout << "=== Entradas Mar Rojo ===" << endl;
    
    //arbolR.print(1);
    //arbolR.print(2);
    //arbolR.print(3);
    //arbolR.print(4);
    arbolR.print(5);
}
