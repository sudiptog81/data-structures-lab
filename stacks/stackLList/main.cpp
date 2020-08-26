/**
 *  Perform the following Stack operations using Linked 
 *  List Representation:
 *    (a)	Push
 *    (b)	Pop
 *    (c)	Clear
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "singlyLinkedList.hpp"

using namespace std;

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
};

int main(void)
{
  Stack<int> stack;

  for (int i = 1; i <= 5; i++)
  {
    cout << "Pushing " << i << "...\n";
    stack.push(i);
  }

  for (int i = 1; i <= 5; i++)
    cout << "Popped " << stack.pop() << "...\n";

  return 0;
}
