#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    vector<string> vect1 = {"Axel", "Pedro", "Fernando", "Jorge", "Carlos", "Karla", "Axel", "Fernando"};
    sort(vect1.begin(),vect1.end());

    vector<string>::iterator low, up;
   
    low = lower_bound(vect1.begin(), vect1.end(), "Faa");
    up = upper_bound(vect1.begin(), vect1.end(), "Faa");
    int posicion = low - vect1.begin();
    
    if(vect1[posicion].substr(0,3) == "Faa"){
        cout << "Encontrado" << endl;
    }
    else{
        cout << "No lo encontre" << endl;
    }

    
  
    
}