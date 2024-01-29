//
// Created by k.t. on 2023/12/11.
//

#ifndef A_OUT_INCLUDE_ITER_HPP_
#define A_OUT_INCLUDE_ITER_HPP_

#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t len, F func) {
  if (!arr) {
    return;
  }
  for (size_t i = 0; i < len; ++i) {
    func(arr[i]);
  }
}

#endif // A_OUT_INCLUDE_ITER_HPP_
