/**
 *  WAP to add two polynomials using linked list representation.
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
  T coeff;
  int exp;
  Node *ptr;
};

template <class T>
class PolynomialList
{
protected:
  Node<T> *head;

public:
  // Constructor
  PolynomialList()
  {
    head = NULL;
  }

  // Destructor
  ~PolynomialList()
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
  void insertNode(T coeff, int exp)
  {
    Node<T> *temp, *node = new Node<T>();
    node->coeff = coeff;
    node->exp = exp;
    node->ptr = NULL;
    if (!this->isEmpty() &&
        head->exp == node->exp)
    {
      head->coeff += node->coeff;
      delete node;
    }
    else if (this->isEmpty() ||
             head->exp > node->exp)
    {
      node->ptr = head;
      head = node;
    }
    else
    {
      temp = head;
      while (temp->ptr != NULL &&
             temp->ptr->exp < node->exp)
        temp = temp->ptr;
      if (temp->ptr != NULL &&
          temp->ptr->exp == node->exp)
      {
        temp->ptr->coeff += node->coeff;
        delete node;
      }
      else if (temp->ptr == NULL &&
               temp->exp == node->exp)
      {
        temp->coeff += node->coeff;
        delete node;
      }
      else
      {
        node->ptr = temp->ptr;
        temp->ptr = node;
      }
    }
    return;
  }

  // Delete node and restore order - O(n)
  int deleteNode(T exp)
  {
    if (this->isEmpty())
      return -1;
    Node<T> *temp = head, *temp1;
    if (head->exp == exp)
    {
      head = temp->ptr;
      delete temp;
    }
    else if (head->exp > exp)
      return 2;
    else
    {
      while (temp->ptr != NULL &&
             temp->ptr->exp < exp)
        temp = temp->ptr;
      if (temp->ptr == NULL)
        return 2;
      else if (temp->ptr->exp == exp)
      {
        temp1 = temp->ptr->ptr;
        delete temp->ptr;
        temp->ptr = temp1;
      }
    }
    return 0;
  }

  // Adds two polynomials - O(n)
  void add(PolynomialList<T> &list1,
           PolynomialList<T> &list2)
  {
    this->~PolynomialList();
    Node<T> *temp1 = list1.head,
            *temp2 = list2.head;
    while (temp1 && temp1->ptr &&
           temp2 && temp2->ptr)
    {
      if (temp1->exp > temp2->exp)
      {
        this->insertNode(temp1->coeff,
                         temp1->exp);
        temp1 = temp1->ptr;
      }
      else if (temp1->exp < temp2->exp)
      {
        this->insertNode(temp2->coeff,
                         temp2->exp);
        temp2 = temp2->ptr;
      }
      else
      {
        this->insertNode(temp1->coeff + temp2->coeff,
                         temp1->exp);
        temp1 = temp1->ptr;
        temp2 = temp2->ptr;
      }
    }
    while (temp1 || temp2)
    {
      if (temp1)
      {
        this->insertNode(temp1->coeff,
                         temp1->exp);
        temp1 = temp1->ptr;
      }
      if (temp2)
      {
        this->insertNode(temp2->coeff,
                         temp2->exp);
        temp2 = temp2->ptr;
      }
    }
    return;
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
      cout << temp->coeff << "x^"
           << temp->exp << " + ";
      temp = temp->ptr;
    }
    cout << temp->coeff << "x^"
         << temp->exp << endl;
    return;
  }
};

template <class T>
void initMain(PolynomialList<T> &list,
              PolynomialList<T> &list2)
{
  T coeff;
  int count, exp;
  cout << "Enter initial number of terms in Polynomial A: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Enter term " << i + 1
         << " for Polynomial A: ";
    cin >> coeff >> exp;
    list.insertNode(coeff, exp);
  }
  cout << endl;
  cout << "Enter initial number of terms in Polynomial B: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Enter term " << i + 1
         << " for Polynomial B: ";
    cin >> coeff >> exp;
    list2.insertNode(coeff, exp);
  }
  getch();
  clrscr();
  return;
}

int main(void)
{
  double coeff;
  int choice, exp, res;
  PolynomialList<double> list, list2, resList;
  initMain<double>(list, list2);
  do
  {
    cout << "\tPolynomials\n"
         << "===================================\n"
         << "  (1) Insert - A  (2) Insert - B\n"
         << "  (3) Delete - A  (4) Delete - B\n"
         << "  (5) Add Polynomials A and B\n"
         << "  (0) Exit\n\n";
    cout << "Polynomial A: ";
    list.display();
    cout << "Polynomial B: ";
    list2.display();
    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter term: ";
      cin >> coeff >> exp;
      list.insertNode(coeff, exp);
      cout << "\nInserted into Polynomial A...\n"
           << "Polynomial A: ";
      list.display();
      break;
    case 2:
      cout << "\nEnter Node info: ";
      cin >> coeff >> exp;
      list2.insertNode(coeff, exp);
      cout << "\nInserted into Polynomial B...\n"
           << "Polynomial B: ";
      list2.display();
      break;
    case 3:
      cout << "\nEnter exponent to Delete: ";
      cin >> exp;
      res = list.deleteNode(exp);
      switch (res)
      {
      case -1:
        cout << "\nPolynomial A is Empty...\n";
        break;
      case 0:
        cout << "\nDeleted from Polynomial A...\n"
             << "Polynomial A: ";
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
      cout << "\nEnter exponent to Delete: ";
      cin >> exp;
      res = list2.deleteNode(exp);
      switch (res)
      {
      case -1:
        cout << "\nPolynomial B is Empty...\n";
        break;
      case 0:
        cout << "\nDeleted from Polynomial B...\n"
             << "Polynomial B: ";
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
      resList.add(list, list2);
      cout << "\nAdded Polynomials...\nSum: ";
      resList.display();
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
