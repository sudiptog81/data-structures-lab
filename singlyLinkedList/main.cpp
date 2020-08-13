/**
 *  Implementation of a Singly Linked List 
 *  
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

void getch();
void clrscr();

template <typename T>
class SinglyLinkedList
{
protected:
  struct Node
  {
    T info;
    Node *ptr;
  };
  struct Node *head, *tail;

public:
  SinglyLinkedList()
  {
    head = tail = NULL;
  }

  ~SinglyLinkedList()
  {
    this->clear();
  }

  void insertFront()
  {
    T info;
    cout << "\nEnter Payload: ";
    cin >> info;
    struct Node *temp = new Node;
    temp->info = info;
    temp->ptr = head;
    if (head == NULL)
      tail = temp;
    head = temp;
    cout << "Inserted " << info
         << " at front...";
    this->display();
    return;
  }

  void insertAtIdx(int idx)
  {
    T info;
    cout << "Enter Payload: ";
    cin >> info;
    struct Node *temp = head,
                *node = new Node;
    node->info = info;
    if (idx == 0)
    {
      if (head == NULL)
      {
        node->ptr = NULL;
        tail = node;
      }
      else
        node->ptr = head;
      head = node;
    }
    else
    {
      for (int i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->ptr;
      if (temp == NULL)
      {
        cout << "Invalid Index...\n";
        return;
      }
      node->ptr = temp->ptr;
      temp->ptr = node;
    }
    cout << "Inserted node " << info
         << " at index " << idx
         << "...";
    this->display();
    return;
  }

  void insertBack()
  {
    T info;
    cout << "\nEnter Payload: ";
    cin >> info;
    struct Node *temp = new Node;
    temp->info = info;
    temp->ptr = NULL;
    if (head == NULL)
      head = tail = temp;
    else
      tail->ptr = temp;
    tail = temp;
    cout << "Inserted " << info
         << " at back...";
    this->display();
    return;
  }

  void deleteFront()
  {
    if (head == NULL || tail == NULL)
    {
      cout << "\nList is empty...\n";
      return;
    }
    head = head->ptr;
    if (head == NULL)
      tail = NULL;
    cout << "\nDeleted node at front...";
    this->display();
    return;
  }

  void deleteAtIdx(int idx)
  {
    if (head == NULL || tail == NULL)
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *node, *temp = head;
    if (idx == 0)
    {
      head = head->ptr;
      if (head == NULL)
        tail = NULL;
    }
    else
    {
      for (int i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->ptr;
      if (temp == NULL || temp->ptr == NULL)
      {
        cout << "Invalid Index...\n";
        return;
      }
      node = temp->ptr->ptr;
      delete temp->ptr;
      temp->ptr = node;
    }
    cout << "Deleted node "
         << "at index " << idx
         << "...";
    this->display();
    return;
  }

  void deleteBack()
  {
    if (head == NULL || tail == NULL)
    {
      cout << "\nList is empty...\n";
      return;
    }
    if (head == tail)
      head = tail = NULL;
    else
    {
      struct Node *temp = head;
      while (temp->ptr->ptr != NULL)
        temp = temp->ptr;
      temp->ptr = NULL;
      tail = temp;
    }
    cout << "\nDeleted node at back...";
    this->display();
    return;
  }

  void reverse()
  {
    if (head == NULL || tail == NULL)
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = head,
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
    cout << "\nList reversed...";
    this->display();
    return;
  }

  void search()
  {
    T info;
    cout << "\nEnter Search Term: ";
    cin >> info;
    struct Node *temp = head;
    while (temp != NULL)
    {
      if (temp->info == info)
      {
        cout << "Element " << info
             << " found...\n";
        return;
      }
      temp = temp->ptr;
    }
    cout << "Element not found...\n";
    return;
  }

  void clear()
  {
    if (head == NULL)
      return;
    struct Node *ptr = NULL,
                *temp = head;
    while (temp->ptr != NULL)
    {
      ptr = temp->ptr;
      delete temp->ptr;
      temp = ptr;
    }
    head = tail = NULL;
    return;
  }

  void display()
  {
    if (head == NULL)
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = head;
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

int main(void)
{
  char payload;
  int choice, idx;
  SinglyLinkedList<char> list;
  do
  {
    cout << "\tSingly Linked List\n"
         << "===================================\n"
         << "  (1) Search      (2) InsertFront\n"
         << "  (3) InsertBack  (4) InsertAtIdx\n"
         << "  (5) DeleteFront (6) DeleteBack\n"
         << "  (7) DeleteAtIdx (8) Display\n"
         << "  (9) Clear       (10) Reverse\n"
         << "  (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      list.search();
      break;
    case 2:
      list.insertFront();
      break;
    case 3:
      list.insertBack();
      break;
    case 4:
      cout << "\nEnter Index: ";
      cin >> idx;
      list.insertAtIdx(idx);
      break;
    case 5:
      list.deleteFront();
      break;
    case 6:
      list.deleteBack();
      break;
    case 7:
      cout << "\nEnter Index: ";
      cin >> idx;
      list.deleteAtIdx(idx);
      break;
    case 8:
      list.display();
      break;
    case 9:
      list.clear();
      cout << "\nList cleared...\n";
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
  cout << "\nPress any to continue...";
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