#include "Array.hpp"

template <typename T> Array<T>::Array() : elements_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array<T> &obj) : elements_(NULL), size_(0) {
  *this = obj;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &obj) {
  if (this == &obj) {
    return *this;
  }
  T *temp_elements = new T[obj.size_]();
  for (size_t i = 0; i < obj.size_; ++i) {
    temp_elements[i] = obj.elements_[i];
  }
  delete[] elements_;
  elements_ = temp_elements;
  size_ = obj.size_;
  return *this;
}

template <typename T> Array<T>::~Array() { delete[] elements_; }

template <typename T> T &Array<T>::operator[](size_t index) const {
  if (index >= size_) {
    throw std::out_of_range("Array index out of range");
  }
  return elements_[index];
}

template <typename T> size_t Array<T>::Size() const { return size_; }