//
// File:   test_q2.cpp
// Author: Darbie Wilson
// Purpose:
// Make a list class
//

#include <iostream>
using namespace std;

int main() {
 bool isBalanced(const string & expression) {
  const char LEFTPAREN = '(';
  const char RIGHTPAREN = ')';
  stack<char> store;
  string:size_type placeInString;
  char next;
  bool failed = false;
  for (i = 0; !failed && (placeInString < expression.length); ++i){
    next = expression[i];
    if (next == LEFTPAREN){
      store.push(next);
    }
    else if ((next == RIGHTPAREN) && !store.empty()) {
      store.pop();
    }
    else if ((next == RIGHTPAREN) && store.empty()) {
      failed = true;
    }
  }
  return (store.empty() && !failed);
 }
  return 0;
}
