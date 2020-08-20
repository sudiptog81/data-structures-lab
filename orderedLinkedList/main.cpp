/**
 *  Write a menu driven program to implement the following operations in 
 *  an ordered linked list:
 *    (a)	Insertion
 *    (b)	Deletion
 *    (c)	Merging
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <cctype>
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
class OrderedLinkedList
{
protected:
  Node<T> *head;

public:
  // Constructor
  OrderedLinkedList()
  {
    head = NULL;
  }

  // Destructor
  ~OrderedLinkedList()
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
    head = NULL;
    return;
  }

  // Checks if the list is empty - O(1)
  bool isEmpty()
  {
    return head == NULL;
  }

  // Insert node in order - O(n)
  void insertNode(T info)
  {
    Node<T> *temp, *node = new Node<T>();
    if (isalpha(info))
      info = (char)(toupper(info));
    node->info = info;
    node->ptr = NULL;
    if (this->isEmpty() ||
        head->info >= node->info)
    {
      node->ptr = head;
      head = node;
    }
    else
    {
      temp = head;
      while (temp->ptr != NULL &&
             temp->ptr->info < node->info)
        temp = temp->ptr;
      node->ptr = temp->ptr;
      temp->ptr = node;
    }
    return;
  }

  // Delete node and restore order - O(n)
  int deleteNode(T info)
  {
    if (this->isEmpty())
      return -1;
    Node<T> *temp = head, *temp1;
    if (isalpha(info) && isalpha(temp->info))
      info = (char)(toupper(info));
    if (head->info == info)
    {
      head = temp->ptr;
      delete temp;
    }
    else if (head->info > info)
      return 2;
    else
    {
      while (temp->ptr != NULL &&
             temp->ptr->info < info)
        temp = temp->ptr;
      if (temp->ptr == NULL)
        return 2;
      else if (temp->ptr->info == info)
      {
        temp1 = temp->ptr->ptr;
        delete temp->ptr;
        temp->ptr = temp1;
      }
    }
    return 0;
  }

  // Helper Function for Merge
  OrderedLinkedList<T> *mergeHelper(OrderedLinkedList<T> *list1,
                                    OrderedLinkedList<T> *list2)
  {
    if (!list1->head->ptr)
    {
      list1->head->ptr = list2->head;
      list2->head = NULL;
      return list1;
    }
    Node<T> *curr1 = list1->head, *next1 = list1->head->ptr,
            *curr2 = list2->head, *next2 = list2->head->ptr;
    list2->head = NULL;
    while (next1 && curr2)
    {
      if ((curr2->info) >= (curr1->info) &&
          (curr2->info) <= (next1->info))
      {
        next2 = curr2->ptr;
        curr1->ptr = curr2;
        curr2->ptr = next1;
        curr1 = curr2;
        curr2 = next2;
      }
      else
      {
        if (next1->ptr)
        {
          next1 = next1->ptr;
          curr1 = curr1->ptr;
        }
        else
        {
          next1->ptr = curr2;
          return list1;
        }
      }
    }
    return list1;
  }

  // Merges two sorted lists - O(n)
  OrderedLinkedList<T> *merge(OrderedLinkedList<T> &list)
  {
    // if (this->isEmpty())
    //   return this;
    // if (list.isEmpty())
    //   return &list;
    // if (head->info < list.head->info)
    //   return mergeHelper(this, &list);
    // else
    //   return mergeHelper(&list, this);
    // return nullptr;

    Node<T> *temp = list.head;
    while (temp != NULL)
    {
      this->insertNode(temp->info);
      temp = temp->ptr;
    }
    return this;
  }

  // Calculates the number of nodes - O(n)
  int count()
  {
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
      cout << "List is empty...\n";
      return;
    }
    Node<T> *temp = head;
    while (temp->ptr != NULL)
    {
      cout << temp->info << " -> ";
      temp = temp->ptr;
    }
    cout << temp->info << endl;
    return;
  }
};

template <class T>
void initMain(OrderedLinkedList<T> &list,
              OrderedLinkedList<T> &list2)
{
  T info;
  int count;
  cout << "Enter initial number of nodes in List A: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Enter info for Node " << i + 1
         << " of List A: ";
    cin >> info;
    list.insertNode(info);
  }
  cout << endl;
  cout << "Enter initial number of nodes in List B: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Enter info for Node " << i + 1
         << " of List B: ";
    cin >> info;
    list2.insertNode(info);
  }
  getch();
  clrscr();
  return;
}

int main(void)
{
  char info;
  int choice, res;
  OrderedLinkedList<char> list, list2, *resList;
  initMain<char>(list, list2);
  do
  {
    cout << "\tOrdered Linked List\n"
         << "===================================\n"
         << "  (1) Insert - A  (2) Insert - B\n"
         << "  (3) Delete - A  (4) Delete - B\n"
         << "  (5) Merge A and B into A\n"
         << "  (0) Exit\n\n";
    cout << "List A: ";
    list.display();
    cout << "List B: ";
    list2.display();
    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Node info: ";
      cin >> info;
      list.insertNode(info);
      cout << "\nInserted " << info
           << " into List A...\n"
           << "List A: ";
      list.display();
      break;
    case 2:
      cout << "\nEnter Node info: ";
      cin >> info;
      list2.insertNode(info);
      cout << "\nInserted " << info
           << " into List B...\n"
           << "List B: ";
      list2.display();
      break;
    case 3:
      cout << "\nEnter Node info to Delete: ";
      cin >> info;
      res = list.deleteNode(info);
      switch (res)
      {
      case -1:
        cout << "\nList A is Empty...\n";
        break;
      case 0:
        cout << "\nDeleted " << info
             << " from List A...\n"
             << "List A: ";
        list.display();
        break;
      case 1:
        cout << "\nInvalid Node info...\n";
        break;
      case 2:
        cout << "\nNode Not Found...\n";
        break;
      }
      break;
    case 4:
      cout << "\nEnter Node info to Delete: ";
      cin >> info;
      res = list2.deleteNode(info);
      switch (res)
      {
      case -1:
        cout << "\nList B is Empty...\n";
        break;
      case 0:
        cout << "\nDeleted " << info
             << " from List B...\n"
             << "List B: ";
        list2.display();
        break;
      case 1:
        cout << "\nInvalid Node info...\n";
        break;
      case 2:
        cout << "\nNode Not Found...\n";
        break;
      }
      break;
    case 5:
      resList = list.merge(list2);
      cout << "\nMerged List B into List A...\n";
      resList->display();
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
