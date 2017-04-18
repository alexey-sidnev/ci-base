#pragma once

#ifndef SOLUTIONS_BASE_VERSION_SRC_TESTS_H_
#define SOLUTIONS_BASE_VERSION_SRC_TESTS_H_

// Генерация элемента случайным образом
template <class Type>
void InitElement(Type *el) {
  *el = Type(rand());
}

// Специализация для типа double
template<>
void InitElement<double>(double *el) {
  *el = (rand() / 2. - RAND_MAX) / (rand() + 1.);
}

// Специализация для типа float
template<>
void InitElement<float>(float *el) {
  *el = (rand() / 2.f - RAND_MAX) / (rand() + 1.f);
}

// Специализация для типа char
// Только заглавные английские буквы
template<>
void InitElement<char>(char *el) {
  *el = rand() % 26 + 65;
}

// Генерация элемента случайным образом типа Complex
template <class Type>
void InitElement(Complex<Type> *el) {
  Type re, im;
  InitElement(&re);
  InitElement(&im);
  *el = Complex<Type>(re, im);
}

// Инициализация массива случайным образом
template <class Type>
void InitArray(Type *mas, int size) {
  for (int i = 0; i < size; ++i)
    InitElement(&mas[i]);
}

// Вывод массива на экран
template <class Type>
void PrintArray(Type *mas, int size) {
  for (int i = 0; i < size; ++i)
    std::cout << "  [" << i << "]=" << mas[i] << std::endl;
}

// Проверка для заданного типа
template <class Type>
void CheckSort(int size) {
  Type *mas = new Type[size];
  InitArray(mas, size);
  std::cout << "Check type: " << typeid(Type).name() << std::endl;
  std::cout << "Initial array:\n";
  PrintArray(mas, size);
  Sorter<Type>::sort(mas, size);
  std::cout << "Sorted array:\n";
  PrintArray(mas, size);
  std::cout << std::endl;
  delete[] mas;
}

#endif  // SOLUTIONS_BASE_VERSION_SRC_TESTS_H_
