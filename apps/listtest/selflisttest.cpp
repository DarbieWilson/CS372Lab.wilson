//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "SelfList.hpp"
void printItem(int &item) {
  std::cout << item << " ";
}

int main() {
  SelfList<int> aListOfIntegers;
  // List test cases, for regression testing
  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 3; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  std::cout << "Test iterators: Mutable -> ";
  for (auto iter = aListOfIntegers.begin();
            iter != aListOfIntegers.end();
            ++iter) {
              std::cout << *iter << " ";
            }

   std::cout << "Test iterators: const -> ";
  for (auto iter = aListOfIntegers.cbegin();
            iter != aListOfIntegers.cend();
            ++iter) {
              std::cout << *iter << " ";
            }
  
  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    int datum = aListOfIntegers.back();
    std::cout << datum << " ";
    aListOfIntegers.pop_back();
  }
  std::cout << std::endl;
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  
  for (int i = 5; i >= 0; --i) {
    aListOfIntegers.push_back(i);
  }
  aListOfIntegers.traverse(printItem);
   std::cout << std::endl;
 
  // SelfList test cases
  SelfList<int>::iterator value = aListOfIntegers.findIt(3);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
   value = aListOfIntegers.findIt(45);
  aListOfIntegers.traverse(printItem);
   std::cout << std::endl;
   value = aListOfIntegers.findIt(3);
  aListOfIntegers.traverse(printItem);
   std::cout << std::endl;
  value = aListOfIntegers.findIt(4);
  aListOfIntegers.traverse(printItem);
   std::cout << std::endl;
  return 0;
}
