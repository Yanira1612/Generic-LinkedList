#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include "Node.h"
//#include "Colection.h"


using namespace std;

template <typename T>
class LinkedList;

template <typename T>
ostream& operator<<(ostream &salida1,const LinkedList<T> &C);
/////////////////

template <typename T>
class LinkedList{
        int size;
        Node<T> *head;
    public:

        LinkedList();
        LinkedList(const LinkedList &);
        LinkedList(LinkedList &&);

        void push_back(Node<T>*);
        void push_front(Node<T>*);
        void push_position(Node<T>*,int);

        void pop_front();
        void pop_back();
        void pop_position(int);
        
        Node<T>* end();
        Node<T>* begin();
        Node<T>* current();

        ~LinkedList();

        friend ostream& operator << <>(ostream &salida1,const LinkedList<T> &C);
        // operator <<
};
//Constructor por defecto

template <typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
}

//Constructor copia
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &o) {
    Node<T>* aux=o.head;
    Node<T>* list=this->head;
    this->size=o.size;
    this->head=nullptr;
        while(aux!=nullptr){
            list=aux;
            aux=aux->getNext();
            list=list->getNext();
        }
}

//Constructor movimiento
template <typename T>
LinkedList<T>::LinkedList(LinkedList &&o) {
    size = o.size;
    head = o.head;

    o.size=0;
    o.head=nullptr;
}

//Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *actual;
    while (head!=nullptr){
        actual = head->getNext();
        delete head;
        head = actual;
    }
    delete head;
}

//PushBack
template <typename T>
void LinkedList<T>::push_back(Node<T>* nuevo){
    end()->setNext(nuevo);
    size++;
}

//push_front
template <typename T>
void LinkedList<T>::push_front(Node<T>* nuevo){
    nuevo->setNext(head);
    head=nuevo;
    size++;
}

//push_position
template <typename T>
void LinkedList<T>::push_position(Node<T>* nuevo,int pos){
    if(pos<size){
        Node<T> *aux, *actual=head;
        if (pos!=0){
            int i=0;
            while(i<pos){
                aux = actual; actual = actual->getNext();
                i++;
            }
            nuevo->setNext(actual);
            aux->setNext(nuevo);

        }
        else{
            nuevo->setNext(head);
            head=nuevo; 
        }
        size++;
    }
}


//pop_front
template <typename T>
void LinkedList<T>::pop_front(){
    head = head -> getNext();
}
//pop_back
template <typename T>
void LinkedList<T>::pop_back(){
    Node<T>* aux=head;
    Node<T>* end=nullptr;
        while(aux->getNext()!=nullptr){
            end=aux;
            aux=aux->getNext();
        }
    end->setNext(nullptr);
}

//pop_position
template <typename T>
void LinkedList<T>::pop_position(int posicion) {
    if(posicion<size){
        Node<T> *aux, *actual=head;
        if (posicion!=0){
            int i=0;
            while(i<posicion){
                aux = actual; actual = actual->getNext();
                i++;
            }
            aux -> setNext( actual->getNext() ); delete actual;
        }
        else{
            head = head -> getNext(); delete actual;
        }
        size--;
    }
}

//end()
template <typename T>
Node<T>* LinkedList<T>::end(){
    Node<T>* end=head;
    while(end->getNext()!=nullptr){
        end=end->getNext();
    }
    return end;
}

//begin()
template <typename T>
Node<T>* LinkedList<T>::begin(){
    Node<T>* begin=head;
    return begin;
}


// overload operator <<
template <typename T>
ostream& operator <<(std::ostream& salida1,const LinkedList<T>& C){
    Node<T>* actual = C.head; 
    salida1 <<" [ ";
    while(actual!=nullptr){
        salida1 << actual->getValue()<<" ";
        actual = actual->getNext();
    }
     salida1 << "] ";

    return salida1;
}


#endif