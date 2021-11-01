#include "Node.h"

#include <queue>
#include <stack>

class BST{  

    public:

        BST();
        ~BST();
        void add(registroNode data);
        void print(int tipo);
		int size();
        

    private:
        NodeT *root;
		void preOrden(NodeT *r);
        void inOrden(NodeT *r);
        void postOrden(NodeT *r);
        void levelByLevel(NodeT *r);
		void reversedInOrden(NodeT *r);
		int size_Helper(NodeT *r);
        void destuye_Helper(NodeT *r);
        
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destuye_Helper(root);
}

// * Método de ayuda para el destroyer de HELPER
// ? Complejidad O(n)
void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

// * Metodo que agrega un dato en el arbol
// ? Complejidad: O(n)
void BST::add(registroNode data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		//int num = data.cant;
		while (curr != nullptr){
			
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		// if (parent->getData() > data){
		// 	parent->setLeft(new NodeT(data));
		// }
		// else{
		// 	parent->setRight(new NodeT(data));
		// }
		parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

// * Metodo que regresa el size del Arbo
// ? Complejodad: O(n)
int BST::size(){
	return size_Helper(root);
}

// * Metodo helper de Size
// ? Complejodad: O(n)
int BST::size_Helper(NodeT *r){
	if (r != nullptr){
		return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
	}
	else{
		return 0;
	}
}

// * Método que regresa la impresion de un arbol por el recorrido:
// * 1 : PreOrden
// * 2 : InOrden
// * 3 : PostOrden
// * 4 : LevelByLevel
// * 5 : InOrden Convexo
// ? Complejidad: O(1)
void BST::print(int tipo){
	switch (tipo){
		case 1 : preOrden(root);
				 break;
		case 2 : inOrden(root);
				 break;
		case 3 : postOrden(root);
				 break;
	    case 4: levelByLevel(root);
		         break;
		case 5:
				reversedInOrden(root);
    }
    cout << endl;
}

// * Metodo que recorre el arbol en preOrden
// ? Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

// * Metodo que recorre el arbol en inOrden
// ? Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

// * Metodo que recorre el arbol en postOrden
// ? Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

// * Metodo que recorre el arbol en levelByLevel
// ? Complejidad: O(n)
void BST::levelByLevel(NodeT *r){
    // * Si root no es nulo, hacemos el recorrido
    if(r != nullptr){

        // * Creacion de la lista y el apuntador al frente de la lista
        NodeT *frente;
        queue<NodeT*> fila;

        // * El primer valor a mandar es root, pues es el nivel 0
        fila.push(r);

        while(fila.size() > 0){
            
            frente = fila.front();

            // * Se imprime el valor del frente (nodo root -> nizq -> nder...)
            cout << frente->getData() << " ";

            // * Sacamos el valor
            fila.pop();

            // * Agregamos hijo izquierdo si encuentra uno
            if(frente->getLeft() != nullptr){
                fila.push(frente->getLeft());
            }

            // * Agragamos hijo derecho si encuentra uno
            if(frente->getRight() != nullptr){
                fila.push(frente->getRight());
            }    
            // * Se vuelve a iterar y ahora el nodo es el hijo izq de root, o en todo caso,
            // * el derecho.
        }
    }
}

// * Metodo que recorre el arbol en reversed inOrden
// ? Complejidad: O(n)
void BST::reversedInOrden(NodeT *r){
	if (r != nullptr){
		
		reversedInOrden(r->getRight());
		cout << r->getData() << " " << endl;
		reversedInOrden(r->getLeft());	
	}
}