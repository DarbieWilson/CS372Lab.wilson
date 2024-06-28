//
// File:   gtesttree.cpp
// Author: Your Glorious Instructor
// Purpose:
// Use Google Test to test our tree class

#include <iostream>
#include <list>
#include "Tree.hpp"

class TreeFixture {
protected:
 Tree<int> aTree({45,74,28,32,44, 100});
  std::list<int> resultList;
  void printIt(int thing) { std::cout << thing; }
  void addToResult(int thing) {resultList.push_back(thing); }
}

// Test: Verify that a preorder traversal happens in correct order
// Precondition: A BST has been created
// Postcondition: A list is created that has the correct preorder walk
//                of the tree.
TEST_F(TreeFixture, PreorderTraversal) {
  aTtree.preorder(addToResult);
  aTree.preorder(printIt);
}

// Test: Verify that a preorder traversal happens in correct order
// Precondition: A BST has been created
// Postcondition: A list is created that has the correct preorder walk
//                of the tree.
TEST_F(TreeFixture, PreorderTraversal) {
  aTtree.postorder(addToResult);
  aTree.postorder(printIt);
}

// Test: Verify that a preorder traversal happens in correct order
// Precondition: A BST has been created
// Postcondition: A list is created that has the correct preorder walk
//                of the tree.
TEST_F(TreeFixture, PreorderTraversal) {
  aTtree.inorder(addToResult);
  aTree.inorder(printIt);
}
