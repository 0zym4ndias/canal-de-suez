
struct registro{
	string fecha;
	string hora;
	char punto;
	string UBI;
	int fechaInt;
	bool operator>(const registro &otro) const{
		//comparar según los criterios
	}
	friend ostream& operator<<(ostream &os, const registro &r);
};

template <class T> 
void LinkedList<T>::sortBurbuja(){ //Funcion que imprime un vector(parametros: vector a evaluar, inicio del vector y final del vector)
  	int pasada = 0;
  	bool interruptor = true;
  	int a;
	Node<T> *curr = head;
    while(curr != nullptr && interruptor){
	cout <<curr -> getData().UBI<< endl;
       for( int j =0; j < this->getSize()-1-pasada; j++){
	    	cout<<curr -> getData().UBI<<endl;
	    	a=(curr -> getData().UBI).compare(curr -> getNext() -> getData().UBI);
//	    	cout<<a<<endl;
//	    	cout<<j<<endl;
	    	if (a == 1){
				this->change(j,j+1);
				interruptor = true;
			}
			pasada++;
		}
		curr = curr -> getNext();
  }
}

//template <class T> 
//void LinkedList<T>::sortBurbuja(){ 
//  bool interruptor = true;
//  int comp = 0, temp;
//  int pasada =0;
//  int a;
//  Node<T> *curr = head;
////   Node<T> *curr2 = head;
//    while(curr != nullptr){
//    	cout<<"Hola"<<endl;
 //   cout <<curr -> getData().UBI<<endl;

//		    for( int j =0; j < this->getSize()-1-pasada; j++){
//		    	
//		    	cout<<curr -> getData().UBI<<endl;
//		    	a=(curr -> getData().UBI).compare(curr -> getNext() -> getData().UBI);
////		    	cout<<a<<endl;
////		    	cout<<j<<endl;
//		    	if (a == 1){
//						this->change(j,j+1);
//						cout<<j<<endl;
//						interruptor = true;
//						cout<<"Hi!"<<endl;
//					}
//				pasada++;
//			}
//	curr = curr -> getNext();
//  	}
//
//}







// Complejidad: Peor Caso O(n^2)   Mejor Caso O(n) cuando ya está ordenado. Pero SIEMPRE registramos peor caso
//int sortBurbuja(vector<int> &vec){
//	bool interruptor = true;
//	int comp = 0, temp;
//	for (int pasada=0; pasada<vec.size() && interruptor; pasada++){
//		interruptor = false;
//		for (int j=0; j<vec.size()-1-pasada; j++){
//			comp++; //Medir las comparaciones
//			if (vec[j+1] < vec[j]){
//				temp = vec[j];
//				vec[j] = vec[j+1];
//				vec[j+1] = temp;
//				interruptor = true;
//			}
//		}
//	}
//	return comp;
//}
//






















template <class T> 
void LinkedList<T>::printAll(){//Funcion que imprime un vector(parametros: vector a evaluar, inicio del vector y final del vector)
  	Node<T> *curr = head;
    while(curr != nullptr){
	cout <<curr -> getData().UBI<<" "<<curr -> getData().fecha <<" "<< curr -> getData().hora<<" "<<curr -> getData().punto<<" "<<endl;
    curr = curr -> getNext();
  }
}
