//
// Created by k.t. on 2023/12/10.
//

#include "iter.hpp"

template <typename T>
void Add_one(T &value) {
  ++value;
}

template <typename T>
void Print(T *arr, size_t len) {
  if (!arr) {
    return;
  }
  for (size_t i = 0; i < len; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  size_t len = 15;
  {
    std::cout << "-----------------INT-----------------" << std::endl;
    int *int_arr = new int[len];
    for (size_t i = 0; i < len; ++i) {
      int_arr[i] = 0;
    }
    iter(int_arr, len, Add_one<int>);
    Print(int_arr, len);
    delete[] int_arr;
  }
  {
    std::cout << "-----------------CHAR-----------------" << std::endl;
    char *char_arr = new char[len];
    for (size_t i = 0; i < len; ++i) {
      char_arr[i] = 'a';
    }
    iter(char_arr, len, Add_one<char>);
    Print(char_arr, len);
    delete[] char_arr;
  }
  {
    std::cout << "-----------------LONG-----------------" << std::endl;
    long *long_arr = new long[len];
    for (size_t i = 0; i < len; ++i) {
      long_arr[i] = 100;
    }
    iter(long_arr, len, Add_one<long>);
    Print(long_arr, len);
    delete[] long_arr;
  }
  {
    std::cout << "-----------------NULL-----------------" << std::endl;
    long *arr = NULL;
    iter(arr, len, Add_one<long>);
    Print(arr, len);
  }
  return 0;
}