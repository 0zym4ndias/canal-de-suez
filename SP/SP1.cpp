/*

Nombre: 
Nombre: 
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 
Descripción: 

*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

struct logSuez{

    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;

};

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

int ftoi(string fecha)
{
    int salida = 0;
    int aux = 0;
    int i = 0;
    while (fecha[i] != '-')
    {
        aux *= 10;
        aux += (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
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

int main(){

    string date, hour, ub, nomArch;
    int dateInt;
    char entryDate;
    bool archFound = true;

    vector<logSuez> vector1;

    cout << "Nombre del archivo -> ";
    cin >> nomArch;

    while(nomArch != "suez.txt"){
        cout << "Archivo no encontrado. Proporcione otro nombre -> ";
        cin >> nomArch;
    }

    ifstream datosSuez;
    datosSuez.open("suez.txt");

    while(datosSuez >> date >> hour >> entryDate >> ub){

        logSuez registro;
        
        registro.fecha = date;
        registro.hora = hour;
        registro.entrada = entryDate;
        registro.ubi = ub;
        registro.fechaInt = ftoi(date);
        vector1.push_back(registro);

    }



    cout << "Funcionando" << endl;

    datosSuez.close();

}
   
    








