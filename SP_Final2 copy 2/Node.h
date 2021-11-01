
template <class T>
class Node
{

public:
    // * Atributos publicos
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext(); // * Regresa un apuntador
    void setData(T data);
    void setNext(Node<T> *next);
    int mestoi();
    
    // * Atributos privados
private:
    T data;
    Node<T> *next;
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr; // * NULL
}

template <class T>
Node<T>::Node(T data, Node<T> *next)
{
    this->data = data;
    this->next = next;
}

template <class T>
T Node<T>::getData(){
    return data;    
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}

template <class T>
int Node<T>::mestoi()
{

    if (getData().mes == "jan")
    {

        return 1;
    }
    if (getData().mes == "feb")
    {

        return 2;
    }
    if (getData().mes == "mar")
    {

        return 3;
    }
    if (getData().mes == "apr")
    {

        return 4;
    }
    if (getData().mes == "may")
    {

        return 5;
    }
    if (getData().mes == "jun")
    {

        return 6;
    }
    if (getData().mes == "jul")
    {

        return 7;
    }
    if (getData().mes == "aug")
    {

        return 8;
    }
    if (getData().mes == "sep")
    {

        return 9;
    }
    if (getData().mes == "oct")
    {

        return 10;
    }
    if (getData().mes == "nov")
    {

        return 11;
    }
    return 12;
}