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

  void create()
  {
    T info;
    struct Node *temp = new Node;
    cout << "\nEnter Payload: ";
    cin >> info;
    temp->info = info;
    temp->ptr = NULL;
    if (head == NULL)
      head = tail = temp;
    else
      tail->ptr = temp;
    tail = temp;
    cout << "Created node " << info
         << "...";
    this->display();
    return;
  };

  void insertFront()
  {
    T info;
    struct Node *temp = new Node;
    cout << "\nEnter Payload: ";
    cin >> info;
    temp->info = info;
    temp->ptr = head;
    head = temp;
    if (head == NULL)
      tail = head;
    cout << "Inserted " << info
         << " at front...";
    this->display();
    return;
  }

  // TODO
  void insertAtIdx(int idx, T info)
  {
    return;
  }

  void insertBack()
  {
    T info;
    struct Node *temp = new Node;
    cout << "\nEnter Payload: ";
    cin >> info;
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

  // TODO
  void deleteAtIdx(int idx)
  {
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

  void clear()
  {
    if (head == NULL)
      return;
    struct Node *ptr = NULL,
                *temp = head;
    while (temp->ptr != NULL)
    {
      ptr = temp->ptr;
      delete temp;
      temp = ptr;
    }
    delete temp;
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
  int choice;
  char payload;
  SinglyLinkedList<char> list;
  do
  {
    cout << "\tSingly Linked List\n"
         << "===================================\n"
         << "  (1) Create      (2) InsertFront\n"
         << "  (3) InsertBack  (4) InsertAtIdx\n"
         << "  (5) DeleteFront (6) DeleteBack\n"
         << "  (7) DeleteAtIdx (8) Display\n"
         << "  (9) Clear List  (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      list.create();
      break;
    case 2:
      list.insertFront();
      break;
    case 3:
      list.insertBack();
      break;
    case 4:
      // TODO
      break;
    case 5:
      list.deleteFront();
      break;
    case 6:
      list.deleteBack();
      break;
    case 7:
      // TODO
      break;
    case 8:
      list.display();
      break;
    case 9:
      list.clear();
      cout << "\nList cleared...\n";
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