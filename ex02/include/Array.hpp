//
// Created by k.t. on 2023/12/11.
//

#ifndef A_OUT_INCLUDE_ARRAY_HPP_
#define A_OUT_INCLUDE_ARRAY_HPP_

#include <iostream>

template <typename T> class Array {
public:
  Array();
  Array(size_t n);
  Array(const Array<T> &obj);
  Array &operator=(const Array<T> &obj);
  ~Array();
  T &operator[](size_t index) const;
  size_t Size() const;

private:
  T *elements_;
  size_t size_;
};

#include "Array.tpp"

#endif // A_OUT_INCLUDE_ARRAY_HPP_
