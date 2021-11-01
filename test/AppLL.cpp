#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "LinkedList.h"

int mestoi(string m){//Funcion para convertir el mes de string a entero(parametro: string a convertir)
	if (m == "jan"){
		return 1;
	}
	if (m == "feb"){
		return 2;
	}
	if (m == "mar"){
		return 3;
	}
	if (m == "apr"){
		return 4;
	}
	if (m == "may"){
		return 5;
	}
	if (m == "jun"){
		return 6;
	}
	if (m == "jul"){
		return 7;
	}
	if (m == "aug"){
		return 8;
	}
	if (m == "sep"){
		return 9;
	}
	if (m == "oct"){
		return 10;
	}
	if (m == "nov"){
		return 11;
	}
	return 12;
}
// Complejidad: O(n)
int ftoi(string fecha){//Función pora convertir la fecha en general a entero(parametro: fecha tipo string)
	int salida = 0;
	int aux = 0;
	int i = 0;
	while (fecha[i] != '-'){
		aux*=10;
		aux+= (fecha[i] - '0');
		i++;
	}
	salida += aux;
	i++;
	string mes = "";
	while (fecha[i] != '-'){
		mes += fecha[i];
		i++;
	}
	salida += (mestoi(mes)*100);
	aux = 0;
	i++;
	while (i < fecha.length()){
		aux *= 10;
		aux += (fecha[i] - '0');
		i++;
	}
	salida += (aux*10000);
	return salida;
}



int main(){
    string fecha, hora, UBI;
    char punto;
    string filename;
    ifstream suez;
    cout << "Nombre del archivo? ";
    cin >> filename;
    suez.open(filename, ios::in);     //Abrir archivo
    if(suez.is_open()){
		LinkedList<registro> mireg, mireg2;
		registro reg;
		suez >> fecha;
        while(!suez.eof()){
            suez >> hora;
            suez >> punto;
            suez >> UBI;
            suez >> fecha;
            reg.fecha = fecha;
			reg.hora = hora;
			reg.punto = punto;
			reg.UBI = UBI;
			reg.fechaInt = ftoi(fecha);
			if(punto == 'R'){
				mireg.addLast(reg);
			}
			else{
				mireg2.addLast(reg);
			}	
    }
    mireg.sortBurbuja();
    mireg.printAll();
}
}

