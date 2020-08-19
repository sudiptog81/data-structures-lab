/**
 *  Implement Circular Linked List using templates. Include functions for 
 *  insertion, deletion and search of a number, reverse the list.
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
class CircularSinglyLinkedList
{
protected:
  Node<T> *tail;

public:
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
    cout << "Inserted " << info << " at front...";
    this->display();
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
    cout << "Inserted node " << info << " at location " << loc << "...";
    this->display();
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
    cout << "Inserted " << info << " at back...";
    this->display();
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
    cout << "\nDeleted node at front...";
    this->display();
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
    cout << "Deleted node "
         << "at location " << loc << "...";
    this->display();
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
    cout << "\nDeleted node at back...";
    this->display();
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
    Node<T> *temp = tail->ptr,
            *prev = NULL,
            *next = NULL;
    while (temp != NULL)
    {
      next = temp->ptr;
      temp->ptr = prev;
      prev = temp;
      temp = next;
    }
    tail = prev;
    cout << "\nList reversed...";
    this->display();
    return;
  }

  // Searches for an element - O(n)
  void search(T ele)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = tail->ptr;
    do
    {
      if (temp->info == ele)
      {
        cout << "Element " << ele << " found...\n";
        return;
      }
      temp = temp->ptr;
    } while (temp != tail->ptr);
    cout << "Element not found...\n";
    return;
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
    Node<T> *temp = tail->ptr;
    do
    {
      temp = temp->ptr;
      count++;
    } while (temp != tail->ptr);
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
    Node<T> *temp = tail->ptr;
    cout << "\nList: ";
    while (temp != tail)
    {
      cout << temp->info << " -> ";
      temp = temp->ptr;
    }
    cout << temp->info << endl;
    return;
  }
};

int main(void)
{
  int info, ele, choice, loc, count;
  CircularSinglyLinkedList<int> list;
  do
  {
    cout << "\tCircular Singly Linked List\n"
         << "===================================\n"
         << "  (1) Search      (2) InsertFront\n"
         << "  (3) InsertBack  (4) InsertAtLoc\n"
         << "  (5) DeleteFront (6) DeleteBack\n"
         << "  (7) DeleteAtLoc (8) Display\n"
         << "  (9) Count       (10) Reverse\n"
         << "  (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Search Element: ";
      cin >> ele;
      list.search(ele);
      break;
    case 2:
      cout << "\nEnter Payload: ";
      cin >> info;
      list.insertFront(info);
      break;
    case 3:
      cout << "\nEnter Payload: ";
      cin >> info;
      list.insertBack(info);
      break;
    case 4:
      cout << "\nEnter Location: ";
      cin >> loc;
      cout << "Enter Payload: ";
      cin >> info;
      list.insertAtLoc(loc, info);
      break;
    case 5:
      list.deleteFront();
      break;
    case 6:
      list.deleteBack();
      break;
    case 7:
      cout << "\nEnter Location: ";
      cin >> loc;
      list.deleteAtLoc(loc);
      break;
    case 8:
      list.display();
      break;
    case 9:
      count = list.count();
      if (count != -1)
        cout << "\nNumber of Nodes: " << count << endl;
      break;
    case 10:
      list.reverse();
      break;
    case 0:
    default:
      break;
    }
    getch();
    clrscr();
  } while (choice != 0);
  return 0;
}

void getch()
{
  cout << "\nPress any key to continue...";
  cin.ignore();
  cin.get();
  return;
}

void clrscr()
{
#ifdef _WIN32
  system("cls");
#elif __unix__
  system("clear");
#endif
  return;
}
