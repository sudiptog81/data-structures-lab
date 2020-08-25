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
    this->list.insertBack(ele);
    return true;
  }

  T pop()
  {
    if (this->isEmpty())
    {
      cout << "ERROR: Stack Underflow\n";
      return (T)(NULL);
    }
    T ele = this->list.getTail();
    this->list.deleteBack();
    return ele;
  }

  T top()
  {
    if (this->isEmpty())
    {
      cout << "Stack Empty";
      return (T)(NULL);
    }
    return this->list.getTail();
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
