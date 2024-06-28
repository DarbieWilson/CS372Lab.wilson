//
// File:   sorter.hpp
// Author: Your Glorious Instructor
// Purpose:
// Build a "device" that can sort a container using a selectable set of
// of sort algorithms.
//
#pragma once
#include <vector>
#include <stack>
#include <utility>
#include <chrono>

class IComparable {
  virtual int compareTo(IComparable &rhs) = 0;
};

template <typename T>
class Sorter {
public:
  Sorter() = default;
  virtual ~Sorter() = default;
  enum  TypeOfSort {QUICKSORT, SELECTION, ITERATIVEQS}  sorttype = QUICKSORT;

  void setSortType(TypeOfSort newSortType) { sorttype = newSortType; }
  
  void sort(std::vector<T> &a) {
    switch (sorttype) {
      case QUICKSORT: 
           quicksort(a, 0, a.size() - 1);
           break;
      case SELECTION:
          selectionSort(a);
          break;
      case ITERATIVEQS:
          quicksortIter(a, 0, a.size() - 1);
          break;
      default:
           std::cerr << "Error: Selected sort not yet implemented in sorter() \n";
    }
  }

  void quicksort(std::vector<T> &a, int start, int end)
  {
    int pivotPosition;
    if (start < end)
    {
      pivotPosition = partition(a, start, end);
      quicksort(a, start, pivotPosition - 1);
      quicksort(a, pivotPosition + 1, end);
    }
  }

  void quicksortIter(std::vector<T> & a, int start, int end) {
      // create a stack of `std::pairs` for storing subarray start and end index
      std::stack<std::pair<int, int>> s;
      auto start = std::chrono::steady_clock::now();
      // push the start and end index of the array into the stack
      s.push(std::make_pair(start, end));
      auto end = std::chrono::steady_clock::now();
      std::chrono::duration<double> elasped_seconds = end - start;
      std::cout << "Elasped wall time: " << elasped_seconds.count();
      // loop till stack is empty
      while (!s.empty()) {
          // remove top pair from the list and get subarray starting
          // and ending indices
          start = s.top().first, end = s.top().second;
          s.pop();
          // rearrange elements across pivot
          int pivot = partition(a, start, end);
          // push subarray indices containing elements that are
          // less than the current pivot to stack
          if (pivot - 1 > start) {
              s.push(std::make_pair(start, pivot - 1));
          }
          // push subarray indices containing elements that are
          // more than the current pivot to stack
          if (pivot + 1 < end) {
              s.push(std::make_pair(pivot + 1, end));
          }
      }
  }
  
  void selectionSort(std::vector<T>& a) {
      int n = a.size();
      for (int i = 0; i < n - 1; i++) {
          int minIndex = i;
          for (int j = i + 1; j < n; j++) {
              if (a[j] < a[minIndex]) {
                  minIndex = j;
              }
          }
          ourSwap(a[minIndex], a[i]);
      }
  }


  TypeOfSort getSortType() const {return sorttype; }

private:
  int partition(std::vector<T> &a, int start, int end)
  {
    T pivotValue;
    int mid;
    mid = start + (end - start) / 2;
    pivotValue = a[mid];
    
    ourSwap(a[mid], a[end]);
    int currentIndex = start - 1;
    for (int scan = start ; scan < end; scan++)
    {
      if (a[scan] < pivotValue)
      {
        currentIndex++;
        ourSwap(a[currentIndex], a[scan]);
      }
    }
    ourSwap(a[currentIndex + 1], a[end]);
    return currentIndex + 1;
  }


  void ourSwap(T &left, T &right)
{
    T temp;
    temp = left;
    left = right;
    right = temp;
  }
};
