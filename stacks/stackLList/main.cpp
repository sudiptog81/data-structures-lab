/**
 *  Perform the following Stack operations using Linked 
 *  List Representation:
 *    (a)	Push
 *    (b)	Pop
 *    (c)	Clear
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

// main.cpp
#include "singlyLinkedList.hpp"

using namespace std;

void getch();
void clrscr();

template <class T>
class Stack
{
protected:
  SinglyLinkedList<T> list;

public:
  bool push(T ele)
  {
    this->list.insertFront(ele);
    return true;
  }

  T pop()
  {
    if (this->isEmpty())
    {
      cout << "ERROR: Stack Underflow\n";
      return (T)(NULL);
    }
    T ele = this->list.getHead();
    this->list.deleteFront();
    return ele;
  }

  T top()
  {
    if (this->isEmpty())
    {
      cout << "Stack Empty";
      return (T)(NULL);
    }
    return this->list.getHead();
  }

  bool isEmpty()
  {
    return this->list.isEmpty();
  }

  void clear()
  {
    while (!this->isEmpty())
      this->pop();
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Stack Empty";
      return;
    }
    int i;
    cout << "Stack: ";
    this->list.display();
    return;
  }
};

int main(void)
{
  int el, res, choice;
  Stack<int> stack;
  do
  {
    cout << "\tStack - SLList\n"
         << "=============================\n"
         << "  (1) Push     (2) Pop\n"
         << "  (3) Top      (4) Clear\n"
         << "  (5) Display  (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Element: ";
      cin >> el;
      res = stack.push(el);
      if (res)
      {
        cout << "\nPushed " << el << "...\n";
        stack.display();
      }
      break;
    case 2:
      res = stack.pop();
      if (res)
      {
        cout << "\nPopped " << res << "...\n";
        stack.display();
      }
      break;
    case 3:
      cout << "\nTop Element: "
           << stack.top() << endl;
      break;
    case 4:
      stack.clear();
      break;
    case 5:
      stack.display();
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
