#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Iterator.h"


template <class T>
class Container {
  friend class Iterator<T, Container>;

 public:
  void Add(T a) {
    m_data_.push_back(a);
  }

  Iterator<T, Container> *CreateIterator() {
    return new Iterator<T, Container>(this);
  }

 private:
  LinkedList<T> m_data_;
};


#endif