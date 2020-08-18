/**
 * Implement Circular Linked List using templates. Include functions for 
 * insertion, deletion and search of a number, reverse the list.
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
  Node *prev;
  Node *next;
};

template <class T>
class CircularDoublyLinkedList
{
protected:
  Node<T> *tail;

public:
  // Constructor
  CircularDoublyLinkedList()
  {
    tail = NULL;
  }

  // Destructor
  ~CircularDoublyLinkedList()
  {
    if (this->isEmpty())
      return;
    Node<T> *ptr, *temp = tail->next;
    while (temp != tail)
    {
      ptr = temp;
      temp = ptr->next;
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
      temp->next = temp;
      temp->prev = temp;
      tail = temp;
    }
    else
    {
      temp->prev = tail;
      temp->next = tail->next;
      tail->next->prev = temp;
      tail->next = temp;
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
    Node<T> *temp = tail->next;
    for (int i = 1; temp->next != tail && i < loc - 1; i++)
      temp = temp->next;
    Node<T> *node = new Node<T>();
    node->info = info;
    node->next = temp->next;
    temp->next->prev = node;
    node->prev = temp;
    temp->next = node;
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
    {
      temp->next = temp;
      temp->prev = temp;
    }
    else
    {
      if (tail->prev == tail)
        tail->prev = temp;
      temp->next = tail->next;
      temp->prev = tail;
      tail->next = temp;
      tail->next->prev = temp;
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
    if (tail->next == tail)
    {
      delete tail;
      tail = NULL;
    }
    else
    {
      Node<T> *temp = tail->next;
      tail->next = temp->next;
      temp->next->prev = tail;
      delete temp;
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
    Node<T> *temp = tail->next;
    for (int i = 1; temp->next != tail && i < loc; i++)
      temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "Deleted node "
         << "at location " << loc << "...";
    this->display();
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
    if (tail->next == tail)
    {
      delete tail;
      tail = NULL;
    }
    else
    {
      Node<T> *temp = tail;
      tail = temp->prev;
      tail->next = temp->next;
      delete temp;
    }
    cout << "\nDeleted node at back...";
    this->display();
    return;
  }

  // Reverses the linked list - O(n)
  // void reverse()
  // {
  //   if (this->isEmpty())
  //   {
  //     cout << "\nList is empty...\n";
  //     return;
  //   }
  //   Node<T> *temp = tail->next,
  //           *temp1 = NULL;
  //   tail = temp;
  //   while (temp != NULL)
  //   {
  //     temp1 = temp->prev;
  //     temp->prev = temp->next;
  //     temp->next = temp1;
  //     temp = temp->prev;
  //   }
  //   if (temp1 != NULL)
  //     tail->next = temp1->prev;
  //   cout << "\nList reversed...";
  //   this->display();
  //   return;
  // }

  // Searches for an element - O(n)
  void search(T ele)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = tail->next;
    do
    {
      if (temp->info == ele)
      {
        cout << "Element " << ele << " found...\n";
        return;
      }
      temp = temp->next;
    } while (temp != tail->next);
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
    Node<T> *temp = tail->next;
    do
    {
      temp = temp->next;
      count++;
    } while (temp != tail->next);
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
    Node<T> *temp = tail->next;
    cout << "\nList: ";
    while (temp != tail)
    {
      cout << temp->info << " -> ";
      temp = temp->next;
    }
    cout << temp->info << endl;
    return;
  }
};

int main(void)
{
  int info, ele, choice, loc, count;
  CircularDoublyLinkedList<int> list;
  do
  {
    cout << "\tCircular Doubly Linked List\n"
         << "===================================\n"
         << "  (1) Search      (2) InsertFront\n"
         << "  (3) InsertBack  (4) InsertAtLoc\n"
         << "  (5) DeleteFront (6) DeleteBack\n"
         << "  (7) DeleteAtLoc (8) Display\n"
         << "  (9) Count       (0) Exit\n\n";
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
    // case 10:
    //   list.reverse();
    //   break;
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
