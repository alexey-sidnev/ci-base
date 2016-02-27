#pragma once

#ifndef SOLUTIONS_BASE_VERSION_SRC_TESTS_H_
#define SOLUTIONS_BASE_VERSION_SRC_TESTS_H_

// ��������� �������� ��������� �������
template <class Type>
void InitElement(Type *el) {
  *el = Type(rand());
}

// ������������� ��� ���� double
template<>
void InitElement<double>(double *el) {
  *el = (rand() / 2. - RAND_MAX) / (rand() + 1.);
}

// ������������� ��� ���� float
template<>
void InitElement<float>(float *el) {
  *el = (rand() / 2.f - RAND_MAX) / (rand() + 1.f);
}

// ������������� ��� ���� char
// ������ ��������� ���������� �����
template<>
void InitElement<char>(char *el) {
  *el = rand() % 26 + 65;
}

// ��������� �������� ��������� ������� ���� Complex
template <class Type>
void InitElement(Complex<Type> *el) {
  Type re, im;
  InitElement(&re);
  InitElement(&im);
  *el = Complex<Type>(re, im);
}

// ������������� ������� ��������� �������
template <class Type>
void InitArray(Type *mas, int size) {
  for (int i = 0; i < size; ++i)
    InitElement(&mas[i]);
}

// ����� ������� �� �����
template <class Type>
void PrintArray(Type *mas, int size) {
  for (int i = 0; i < size; ++i)
    std::cout << "  [" << i << "]=" << mas[i] << std::endl;
}

// �������� ��� ��������� ����
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
