/**
 *  Perform the following Queue operations using Circular Linked
 *  List implementation (Use Templates):
 *    (a)	Enqueue
 *    (b)	Dequeue
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "circularSinglyLinkedList.hpp"

using namespace std;

void getch();
void clrscr();

template <class T>
class Queue
{
protected:
  Node<T> *front, *rear;
  CircularSinglyLinkedList<T> list;

public:
  Queue()
  {
    this->front = this->list.tail;
    this->rear = this->list.tail;
  }

  bool enqueue(T ele)
  {
    this->list.insertBack(ele);
    this->front = this->list.tail->ptr;
    this->rear = this->list.tail;
    return true;
  }

  T dequeue()
  {
    if (this->isEmpty())
    {
      cout << "ERROR: Queue Empty\n";
      return (T)(NULL);
    }
    T temp = this->front->info;
    this->list.deleteFront();
    if (this->isEmpty())
      this->front = this->list.tail;
    else
      this->front = this->list.tail->ptr;
    this->rear = this->list.tail;
    return temp;
  }

  T frontEl()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return (T)(NULL);
    }
    return this->front->info;
  }

  bool isEmpty()
  {
    return this->list.isEmpty();
  }

  void clear()
  {
    while (!this->isEmpty())
      this->dequeue();
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return;
    }
    this->list.display();
    return;
  }
};

int main(void)
{
  int el, res, choice;
  Queue<int> q;
  do
  {
    cout << "\tCircular Queue - CSLList\n"
         << "===================================\n"
         << "  (1) Enqueue  (2) Dequeue\n"
         << "  (3) Front    (4) Clear\n"
         << "  (5) Display  (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Element: ";
      cin >> el;
      res = q.enqueue(el);
      if (res)
      {
        cout << "\nEnqueued " << el << "...\n";
        cout << "Queue: ";
        q.display();
      }
      break;
    case 2:
      res = q.dequeue();
      if (res)
      {
        cout << "\nDequeued " << res << "...\n";
        cout << "Queue: ";
        q.display();
      }
      break;
    case 3:
      cout << "\nFront Element: "
           << q.frontEl() << endl;
      break;
    case 4:
      q.clear();
      break;
    case 5:
      cout << "\nQueue: ";
      q.display();
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
