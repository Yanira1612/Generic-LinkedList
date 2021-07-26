#include <iostream>
#include "LinkedList.h"

#include "Node.h"
#include "Iterator.h"
#include "Container.h"

using namespace std;

int main() {

//NODOS INT
    Node<int> a(12);
    Node<int> b(13);
    Node<int> c(14);
    Node<int> d(15);

//LISTA NODO INT
    LinkedList<int> l1;

    l1.push_front(&a);
    l1.push_back(&b);
    l1.push_position(&c,1);

    cout << l1 << endl;

    l1.pop_position(0);

    cout << l1 << endl;
//////////////////////////////

//NODOS STRING
    Node<string> a1("a");
    Node<string> b1("b");
    Node<string> c1("c");
    Node<string> d1("d");

// LISTA NODO STRING
    LinkedList<string> l2;

    l2.push_front(&a1);
    l2.push_front(&b1);
    l2.push_back(&c1);
    l2.push_position(&d1,1);

    cout<<l2<<endl;

  LinkedList<string> l3(move(l2));

  cout<<l3<<endl;

//////////////////

/*
Container<Node<int>> container;
  Node<int> a(100), b(1000), c(10000);
  container.Add(a);
  container.Add(b);
  container.Add(c);

Iterator<Node<int>, Container<int>> *iterar = container.CreateIterator();
        for (iterar->First(); !iterar->IsDone(); iterar->Next()) {
    std::cout << iterar->Current()->data() << std::endl;
  }

  delete iterar;
*/ 


    return 0;

}