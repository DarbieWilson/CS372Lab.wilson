//
// File:   gtestlist.cpp
// Author: Your Glorious Instructor
// Purpose:
// Test our list class using Google Test

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "sorter.hpp"
using namespace std;

// Test fixtures manage the state of the test. 
// Test fixtures are subclass of the ::testing::Test class, with
// all contents set as protected.   As we are using member 
// variables not allocated on the heap, no need to do any
// special setup or teardown.  Do need to use the TEST_F() macro
// rather TEST()


class SortTest: public ::testing::Test {
protected:
  SortTest() {

  }

  vector<int> testData1 = {8, 5, 6, 4, 100, 32, 1000};
  vector<int> testData2;
  vector<std::string> testData3 = {"Tom", "Harry", "Dick", "Ringo", "George", "John", "Paul"};

  int giveMeARandomInt(int start, int end) {
    std::random_device r;
    std::default_random_engine eng1(r());
    std::uniform_int_distribution<int> uniGenerator(start,end);
    return uniGenerator(eng1);

  }
  void fillWithRandomIntegers(std::vector<int> &v, int numberItems) {
    for (int i=0; i < numberItems; ++i) {
      v[i] = giveMeARandomInt(0, 100000);
    }
  }
};

// Test: Default sort algorithm is Quicksort
// Precondition: None
// Postcondition: A default created sort configured to use Quicksort
TEST_F(SortTest, DefaultSortIsQuicksort) {
  Sorter<int> s;
  EXPECT_EQ(Sorter<int>::TypeOfSort::QUICKSORT, s.getSortType());
}

// Test: Sort algorithm is correctly set when manually changed
// Precondition: A sorter object exists with the default value of Quicksort
// Postcondition: That sorter object is reset to use Selection Sort
TEST_F(SortTest, ChangeSortAlgorithm) {
  Sorter<int> s;
  s.setSortType(Sorter<int>::TypeOfSort::SELECTION);
  EXPECT_EQ(Sorter<int>::TypeOfSort::SELECTION, s.getSortType());
}

// Test: Sort algorithm is correctly set when manually changed
// Precondition: A sorter object exists with the default value of Quicksort
// Postcondition: That sorter object is reset to use Selection Sort
TEST_F(SortTest, ChangeSortAlgorithmToIterativeQS) {
    Sorter<int> s;
    s.setSortType(Sorter<int>::TypeOfSort::ITERATIVEQS);
    EXPECT_EQ(Sorter<int>::TypeOfSort::ITERATIVEQS, s.getSortType());
}
// Test: Verify that the sorter can handle multiple types of data
// Precondition: A sorter object is created for sorting strings
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanSortStrings) {
  std::vector<std::string> sortedTestData3 = {"Dick", "George", "Harry", "John", "Paul", "Ringo", "Tom"};
  Sorter<std::string> s;
  s.sort(testData3);
  for (auto aString : testData3) { std::cout << aString << std::endl; }
  EXPECT_EQ(testData3, sortedTestData3);
}

// Test: Verify that the sorter can handle multiple types of data
// Preconditon: A sorter object is created for sorting integers
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanSortInts) {
  std::vector<int> testData = {3, 5, 2, 4, 8, 7, 9, 1, 10,6};
  std::vector<int> sortedData = {1,2,3,4,5,6,7,8,9,10};
  Sorter<int> s;
  s.sort(testData);
  for (auto anInt : testData) { std::cout << anInt << std::endl; }
  EXPECT_EQ(testData, sortedData);
}


// Test: Verify that the sorter can handle multiple types of data
// Precondition: A sorter object is created for sorting strings
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanSelectSortStrings) {
    std::vector<std::string> sortedTestData3 = { "Dick", "George", "Harry", "John", "Paul", "Ringo", "Tom" };
    Sorter<std::string> s;
    s.setSortType(Sorter<std::string>::TypeOfSort::SELECTION); 
    s.sort(testData3);
    for (auto aString : testData3) { std::cout << aString << std::endl; }
    EXPECT_EQ(testData3, sortedTestData3);
}

// Test: Verify that the sorter can handle multiple types of data
// Preconditon: A sorter object is created for sorting integers
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanSelectSortInts) {
    std::vector<int> testData = { 3, 5, 2, 4, 8, 7, 9, 1, 10,6 };
    std::vector<int> sortedData = { 1,2,3,4,5,6,7,8,9,10 };
    Sorter<int> s;
    s.setSortType(Sorter<int>::TypeOfSort::SELECTION);
    s.sort(testData);
    for (auto anInt : testData) { std::cout << anInt << std::endl; }
    EXPECT_EQ(testData, sortedData);
}

// Test: Verify that the sorter can handle multiple types of data
// Precondition: A sorter object is created for sorting strings
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanIterQuicksortStrings) {
    std::vector<std::string> sortedTestData3 = { "Dick", "George", "Harry", "John", "Paul", "Ringo", "Tom" };
    Sorter<std::string> s;
    s.setSortType(Sorter<std::string>::TypeOfSort::ITERATIVEQS);
    s.sort(testData3);
    for (auto aString : testData3) { std::cout << aString << std::endl; }
    EXPECT_EQ(testData3, sortedTestData3);
}

// Test: Verify that the sorter can handle multiple types of data
// Preconditon: A sorter object is created for sorting integers
// Postcondition: The testdata is in sorted order
TEST_F(SortTest, CanIterQuicksortInts) {
    std::vector<int> testData = { 3, 5, 2, 4, 8, 7, 9, 1, 10,6 };
    std::vector<int> sortedData = { 1,2,3,4,5,6,7,8,9,10 };
    Sorter<int> s;
    s.setSortType(Sorter<int>::TypeOfSort::ITERATIVEQS);
    s.sort(testData);
    for (auto anInt : testData) { std::cout << anInt << std::endl; }
    EXPECT_EQ(testData, sortedData);
}