//
// File:   Dictionary.hpp
// Author: Your Glorious Instructor
// Purpose:
// A simplified implementation of the Dictionary ADT
//
#pragma once
#include <iostream>
#include <stdexcept>
#include "Tree.hpp"
#include "Pair.hpp"

template <typename KeyType, typename ValueType>
class Dictionary {
private:
  Tree<Pair<KeyType,ValueType>> dictTree;
public:
  Dictionary<KeyType, ValueType>() = default;
  bool empty() {
    return dictTree.isEmpty();
  }

  size_t size() {
    return dictTree.size();
  }
  
  void insert(KeyType key, ValueType value) {
    Pair<KeyType, ValueType> newEntry = MakePair(key, value);
    dictTree.insert(newEntry);
  }

  

  ValueType & at(const KeyType item) {
    ValueType theValue;
    Pair<KeyType, ValueType> thePair = MakePair(item, theValue);
    bool inTree = dictTree(thePair, thePair);
    if (inTree) {
      return thePair.second;
    }
    else {
      throw std::out_of_range("Item does not exist in Dictionary");
    }
  }

  ValueType & operator[](const KeyType item) {
    return at(item);
  }

};
