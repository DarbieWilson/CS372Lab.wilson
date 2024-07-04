//
// File:   assignment6.cpp
// Author: Darbie Wilson
// Purpose:
// Make a list class
//

#include <iostream>
using namespace std;
{
template<class V>
class Tree{
  private:
    struct Node {
      Node(V v, Node * l, Node * r): value(v), left(l), right(r){}
      V value;
      Node *left;
      Node *right;
    };
    explicit Tree(Node * node): root(node) {}
    Node * root;
  public:
  Tree() {}
  Tree(Tree *lft, V value, Tree *rgt) :
    root(Node(val, lft->root, rgt->root)) {}
    bool isEmpty() const;
    V root() const;
    Tree *left() const;
    Tree *right() const;
    bool member(V x) const;
    bool isLeaf() const;
}

Tree insert(T x) const{
  if (isEmpty())
    return Tree(Tree(), x, Tree());
  T y = root();
  if (x < y)
    return Tree(left().insert(x), y, right());
  else if (y < x)
    return Tree(left(), y, right().insert(x));
  else  
    return *this; 
}

  return 0;
}
