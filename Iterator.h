#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <iostream>
#include "LinkedList.h"
#include "Node.h"


template <typename T, typename U>
class Iterator {
  typedef typename LinkedList<T>::Iterator iter_type;
 private:
  U *m_p_data_;
  iter_type m_it_;

 public:
  
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void First() {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void Next() {
    m_it_++;
  }

  bool IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
  }

  iter_type Current() {
    return m_it_;
  }

};

#endif