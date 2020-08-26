/**
 * Implement Linked List using templates. Include functions for
 * insertion, deletion and search of a number, reverse the list and
 * concatenate two linked lists (include a function and also overload 
 * operator +). 
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

void getch();
void clrscr();

template <class T>
class Node
{
public:
  T info;
  Node *ptr;
};

template <class T>
class SinglyLinkedList
{
protected:
  Node<T> *head, *tail;

public:
  // Constructor
  SinglyLinkedList()
  {
    head = tail = NULL;
  }

  // Destructor
  ~SinglyLinkedList()
  {
    if (this->isEmpty())
      return;
    Node<T> *ptr, *temp = head;
    while (temp != NULL)
    {
      ptr = temp->ptr;
      delete temp;
      temp = ptr;
    }
    head = tail = NULL;
    return;
  }

  // Returns the data on the head of the list - O(1)
  T getHead()
  {
    return this->isEmpty() ? (T)(NULL) : head->info;
  }

  // Checks if the list is empty - O(1)
  bool isEmpty()
  {
    return (head == NULL || tail == NULL);
  }

  // Inserts a node at the beginning - O(1)
  void insertFront(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    temp->ptr = head;
    if (this->isEmpty())
      tail = temp;
    head = temp;
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
    Node<T> *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->ptr;
    if (temp == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp == tail)
    {
      this->insertBack(info);
      return;
    }
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
    temp->ptr = NULL;
    if (this->isEmpty())
      head = tail = temp;
    else
      tail->ptr = temp;
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
    Node<T> *temp = head;
    head = temp->ptr;
    delete temp;
    if (this->isEmpty())
      tail = NULL;
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
    if (loc == 1)
    {
      this->deleteFront();
      return;
    }
    Node<T> *node, *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->ptr;
    if (temp == NULL || temp->ptr == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp == tail)
    {
      this->deleteBack();
      return;
    }
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
    if (head == tail)
    {
      this->deleteFront();
      return;
    }
    else
    {
      Node<T> *temp = head;
      while (temp->ptr->ptr != NULL)
        temp = temp->ptr;
      delete temp->ptr;
      temp->ptr = NULL;
      tail = temp;
    }
    return;
  }

  // Reverses the linked list - O(n)
  void reverse()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = head,
            *prev = NULL,
            *next = NULL;
    tail = temp;
    while (temp != NULL)
    {
      next = temp->ptr;
      temp->ptr = prev;
      prev = temp;
      temp = next;
    }
    head = prev;
    return;
  }

  // Concatenates two lists - O(n)
  void concat(SinglyLinkedList<T> &list)
  {
    if (!list.isEmpty() && !this->isEmpty())
    {
      Node<T> *node,
          *temp = tail,
          *temp1 = list.head;
      while (temp1 != NULL)
      {
        node = new Node<T>();
        node->info = temp1->info;
        node->ptr = NULL;
        temp->ptr = node;
        temp = temp->ptr;
        temp1 = temp1->ptr;
      }
      tail = node;
    }
    return;
  }

  // Overloads the + operator - O(n)
  void operator+(SinglyLinkedList<T> &list)
  {
    this->concat(list);
    return;
  }

  // Searches for an element - O(n)
  bool search(T ele)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return false;
    }
    Node<T> *temp = head;
    while (temp != NULL)
    {
      if (temp->info == ele)
        return true;
      temp = temp->ptr;
    }
    return false;
  }

  // Calculates the number of nodes - O(n)
  int count()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return -1;
    }
    int count = 0;
    Node<T> *temp;
    for (temp = head; temp != NULL;
         temp = temp->ptr, count++)
      ;
    return count;
  }

  // Traverses the list and prints all nodes - O(n)
  void display()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = head;
    cout << "\nList: ";
    while (temp->ptr != NULL)
    {
      cout << temp->info << " -> ";
      temp = temp->ptr;
    }
    cout << temp->info << endl;
    return;
  }
};
