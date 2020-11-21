// doublyLinkedList.hpp
#include <iostream>

using namespace std;

void getch();
void clrscr();

template <class T>
class Node
{
public:
  T info;
  Node *prev;
  Node *next;
};

template <class T>
class DoublyLinkedList
{
public:
  Node<T> *head, *tail;

  // Constructor
  DoublyLinkedList()
  {
    head = tail = NULL;
  }

  // Destructor
  ~DoublyLinkedList()
  {
    if (this->isEmpty())
      return;
    Node<T> *ptr;
    for (; !isEmpty();)
    {
      ptr = head->next;
      delete head;
      head = ptr;
    }
    head = tail = ptr;
    return;
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
    temp->next = head;
    temp->prev = NULL;
    if (this->isEmpty())
      tail = temp;
    else
      head->prev = temp;
    head = temp;
    return;
  }

  // Inserts a node at the end - O(1)
  void insertBack(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    temp->next = NULL;
    temp->prev = tail;
    if (this->isEmpty())
      head = tail = temp;
    else
      tail->next = temp;
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
    head = temp->next;
    if (this->isEmpty())
      tail = NULL;
    else
      head->prev = NULL;
    delete temp;
    return;
  }

  // Removes a node at the end - O(1)
  void deleteBack()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = tail;
    tail = temp->prev;
    if (this->isEmpty())
      head = NULL;
    else
      tail->next = NULL;
    delete temp;
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
    Node<T> *temp = head;
    while (temp->next != NULL)
    {
      cout << temp->info << " -> ";
      temp = temp->next;
    }
    cout << temp->info << endl;
    return;
  }
};
