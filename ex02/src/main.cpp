#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

template<typename T>
int test() {
  Array<T> numbers(MAX_VAL);
  T *mirror = new T[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const T value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  {
    Array<T> tmp = numbers;
    Array<T> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  std::cerr << "test passed" << std::endl;
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;
  return 0;
}

int main() {
  test<int>();
  test<long>();
  test<unsigned int>();
  test<size_t>();
  system("leaks -q a.out");
  return 0;
}