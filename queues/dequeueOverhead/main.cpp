/**
 *  Implement queue using stacks by adding overhead (cost) to 
 *  dequeue operation.
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "stack.hpp"

using namespace std;

void getch();
void clrscr();

template <class T>
class Queue
{
protected:
  T front, rear;
  Stack<T> stack1, stack2;

public:
  Queue()
  {
    this->front = this->rear = (T)(NULL);
  }

  bool enqueue(T ele)
  {
    bool flag = false;
    if (this->isEmpty())
      flag = true;
    this->stack1.push(ele);
    this->rear = this->stack1.top();
    if (flag)
      this->front = this->rear;
    return true;
  }

  T dequeue()
  {
    if (this->isEmpty())
    {
      cout << "ERROR: Queue Empty\n";
      return (T)(NULL);
    }
    if (this->stack2.isEmpty())
      while (!this->stack1.isEmpty())
        this->stack2.push(this->stack1.pop());
    T temp = this->stack2.pop();
    if (!this->stack2.isEmpty())
      this->front = this->stack2.top();
    while (!this->stack2.isEmpty())
      this->stack1.push(this->stack2.pop());
    if (!this->stack1.isEmpty())
      this->rear = this->stack1.top();
    else
      this->rear = this->front = (T)(NULL);
    return temp;
  }

  T frontEl()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return (T)(NULL);
    }
    return this->front;
  }

  bool isEmpty()
  {
    return this->stack1.isEmpty() && this->stack2.isEmpty();
  }

  void clear()
  {
    this->stack1.clear();
    this->stack2.clear();
    this->front = this->rear = (T)(NULL);
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return;
    }
    cout << "Queue: ";
    this->stack1.display();
    return;
  }
};

int main(void)
{
  Queue<int> q;
  int el, res, choice;
  do
  {
    cout << "     Queue - Dequeue Overhead\n"
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
        q.display();
      }
      break;
    case 2:
      res = q.dequeue();
      if (res)
      {
        cout << "\nDequeued " << res << "...\n";
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
