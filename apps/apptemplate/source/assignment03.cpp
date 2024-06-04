//
// File:   assignment3.cpp
// Author: Darbie Wilson
// Purpose:
// Make a list class
//

#include <iostream>
using namespace std;

template <typename T>
class List {
  private:
    class Node{
      public:
        T data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
  public:
    List();
    List (T newData);
    List(List& rhs); // copy constructor
    ~List();
    bool empty();
    void push_front(T data);
    void push_back(T data);
    T front();
    T back();
    void pop_back();
    void pop_front();
    void traverse(void (*doIt)(T data));
};

int main() {

// Helper Function
void setupList() 
{
  Node* newNode = new Node();
  newNode->next = nullptr;
  newNode->prev = nullptr;
  head = newNode;
  tail = nedNode;
}

// Construct
List () 
{
  setupList();
}

List(T newData)
{
  setupList();
  head->data = newData;
}

// Destruct
~List()
{
  Node* current = head;
  Node* temp = nullptr;
  while (current != nullptr)
  {
    temp = current.next;
    delete current;
    current = temp;
  }
}

// Copy Constructor
List(List& rhs)
{
  Node* current = head;
  Node* temp = nullptr;
  while (current != nullptr)
  {
    temp = current.next;
    delete current;
    current = temp;
  }
  head = rhs.head;
  tail = rhs.tail;
}

// Delete List Contents
void deleteListContents()
{
  Node* current = head;
  Node* temp = nullptr;
  while (current != nullptr)
  {
    temp = current.next;
    delete current;
    current = temp;
  }
}

// Adding to the List
void push_front (T data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  newNode->prev = nullptr;
  head = newNode;
}

// Add to the end of the List
void push_back (T data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = tail;
  tail = newNode;
}

// Traversing the List
T front()
{
  return (head->data);
}

T back()
{
  return (tail->data);
}

// Pop
void pop_back()
{
  Node *lastNode = tail;
  tail = tail.prev;
  tail.next = nullptr;
  delete lastNode;
}

void pop_front()
{
  Node *firstNode = head;
  head = head.prev;
  head.next = nullptr;
  delete firstNode;
}


// Print
void printTheList()
{
  Node* current = head;
  while (current != tail)
  {std::cout << current->data << " ";}
  std::cout << std::endl;
}

  return 0;
}
