#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {    
    private:
        T value;
        Node<T> *next;
    public:
        Node(T _value = 0 , Node<T>* _next = nullptr): 
            value(_value), next(_next){}

		T getValue() ;
        void setValue(T);

		Node<T>* getNext() ;               
        void setNext(Node<T>*);

};

template <typename T>
void Node<T>::setValue(T _value){
    this->value = _value;
}

template <typename T>
T Node<T>::getValue()  {
    return value;
}

template <typename T>
void Node<T>::setNext(Node<T> *_next){
    this->next = _next;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

#endif