//
// File:   assignment1.cpp
// Author: Darbie Wilson
// Purpose:
// Illustrate some of the bad thins that can happen with
// pointers
//
#include <iostream>
using namespace std;


int main() {

  double arrayPtr;
  double *dptr;
  dptr = new double;
  // This function uses new to allocate a large array of integers in the heap.

  cout << &arrayPtr << "      ";
  cout << dptr;

  const int SIZE = 25;
  arrayPtr = new double[SIZE];
  for (int i = 0; i < SIZE; i++) {
      *arrayPtr[i] = i*i;
      *(arrayPtr + i) = i*i;
  }
 
  return 0;
}
