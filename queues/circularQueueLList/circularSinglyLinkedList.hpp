/**
 *  Implement Circular Linked List using templates. Include functions for 
 *  insertion, deletion and search of a number, reverse the list.
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

// circularSinglyLinkedList.hpp
#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
  T info;
  Node *ptr;
};

template <class T>
class CircularSinglyLinkedList
{
public:
  Node<T> *tail;

  // Constructor
  CircularSinglyLinkedList()
  {
    tail = NULL;
  }

  // Destructor
  ~CircularSinglyLinkedList()
  {
    if (this->isEmpty())
      return;
    Node<T> *ptr, *temp = tail->ptr;
    while (temp != tail)
    {
      ptr = temp;
      temp = ptr->ptr;
      delete ptr;
    }
    delete temp;
    tail = NULL;
    return;
  }

  // Checks if the list is empty - O(1)
  bool isEmpty()
  {
    return tail == NULL;
  }

  // Inserts a node at the beginning - O(1)
  void insertFront(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    if (this->isEmpty())
    {
      temp->ptr = temp;
      tail = temp;
    }
    else
    {
      temp->ptr = tail->ptr;
      tail->ptr = temp;
    }
    return;
  }

  // Inserts a node at a specified location - O(n)
  void insertAtLoc(int loc, T info)
  {
    if (loc == 1)
    {
      this->insertFront(info);
      return;
    }
    int size = this->count();
    if (loc > size + 1 || loc < 1)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (loc == size + 1)
    {
      this->insertBack(info);
      return;
    }
    Node<T> *temp = tail->ptr;
    for (int i = 1; temp->ptr != tail && i < loc - 1; i++)
      temp = temp->ptr;
    Node<T> *node = new Node<T>();
    node->info = info;
    node->ptr = temp->ptr;
    temp->ptr = node;
    return;
  }

  // Inserts a node at the end - O(1)
  void insertBack(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    if (this->isEmpty())
      temp->ptr = temp;
    else
    {
      temp->ptr = tail->ptr;
      tail->ptr = temp;
    }
    tail = temp;
    return;
  }

  // Removes a node from the beginning - O(1)
  void deleteFront()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    else if (tail->ptr == tail)
    {
      delete tail;
      tail = NULL;
    }
    else
    {
      Node<T> *temp;
      temp = tail->ptr->ptr;
      delete tail->ptr;
      tail->ptr = temp;
    }
    return;
  }

  // Removes a node at a specified location - O(n)
  void deleteAtLoc(int loc)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    int size = this->count();
    if (loc > size || loc < 1)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (loc == size)
    {
      this->deleteBack();
      return;
    }
    Node<T> *node, *temp = tail->ptr;
    for (int i = 1; temp->ptr != tail && i < loc - 1; i++)
      temp = temp->ptr;
    node = temp->ptr->ptr;
    delete temp->ptr;
    temp->ptr = node;
    return;
  }

  // Removes a node at the end - O(n)
  void deleteBack()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    else if (tail->ptr == tail)
    {
      delete tail;
      tail = NULL;
    }
    else
    {
      Node<T> *temp = tail->ptr;
      while (temp->ptr != tail)
        temp = temp->ptr;
      temp->ptr = tail->ptr;
      delete tail;
      tail = temp;
    }
    return;
  }

  // Traverses the list and prints all nodes - O(n)
  void display()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = tail->ptr;
    while (temp != tail)
    {
      cout << temp->info << " -> ";
      temp = temp->ptr;
    }
    cout << temp->info << endl;
    return;
  }
};
