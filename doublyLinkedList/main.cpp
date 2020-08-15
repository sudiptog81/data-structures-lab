/**
 *  Implementation of a Doubly Linked List
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

void getch();
void clrscr();

template <typename T>
class DoublyLinkedList
{
protected:
  struct Node
  {
    T info;
    Node *prev;
    Node *next;
  };
  struct Node *head, *tail;

public:
  DoublyLinkedList()
  {
    head = tail = NULL;
  }

  ~DoublyLinkedList()
  {
    if (this->isEmpty())
      return;
    struct Node *ptr, *temp = head;
    while (temp != NULL)
    {
      ptr = temp->next;
      delete temp;
      temp = ptr;
    }
    head = tail = NULL;
    return;
  }

  bool isEmpty()
  {
    return (head == NULL || tail == NULL);
  }

  void insertFront(T info)
  {
    struct Node *temp = new Node();
    temp->info = info;
    temp->next = head;
    temp->prev = NULL;
    if (this->isEmpty())
      tail = temp;
    else
      head->prev = temp;
    head = temp;
    cout << "Inserted " << info << " at front...";
    this->display();
    return;
  }

  void insertAtLoc(int loc, T info)
  {
    if (loc == 1)
    {
      this->insertFront(info);
      return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->next;
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
    struct Node *node = new Node();
    node->info = info;
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;
    cout << "Inserted node " << info << " at location " << loc << "...";
    this->display();
    return;
  }

  void insertBack(T info)
  {
    struct Node *temp = new Node();
    temp->info = info;
    temp->next = NULL;
    temp->prev = tail;
    if (this->isEmpty())
      head = tail = temp;
    else
      tail->next = temp;
    tail = temp;
    cout << "Inserted " << info << " at back...";
    this->display();
    return;
  }

  void deleteFront()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = head;
    head = temp->next;
    if (this->isEmpty())
      tail = NULL;
    else
      head->prev = NULL;
    delete temp;
    cout << "\nDeleted node at front...";
    this->display();
    return;
  }

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
    struct Node *node, *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp->next == tail)
    {
      this->deleteBack();
      return;
    }
    node = temp->next->next;
    node->prev = temp;
    delete temp->next;
    temp->next = node;
    cout << "Deleted node "
         << "at location " << loc << "...";
    this->display();
    return;
  }

  void deleteBack()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = tail;
    tail = temp->prev;
    if (this->isEmpty())
      head = NULL;
    else
      tail->next = NULL;
    delete temp;
    cout << "\nDeleted node at back...";
    this->display();
    return;
  }

  void search(T ele)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
      if (temp->info == ele)
      {
        cout << "Element " << ele << " found...\n";
        return;
      }
      temp = temp->next;
    }
    cout << "Element not found...\n";
    return;
  }

  int count()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return -1;
    }
    int count = 0;
    struct Node *temp;
    for (temp = head; temp != NULL;
         temp = temp->next, count++)
      ;
    return count;
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    struct Node *temp = head;
    cout << "\nList: ";
    while (temp->next != NULL)
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
  DoublyLinkedList<int> list;
  do
  {
    cout << "\tDoubly Linked List\n"
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
