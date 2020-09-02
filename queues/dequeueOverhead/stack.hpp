/**
 *  Perform the following Stack operations using Array 
 *  implementation using Templates:
 *    (a)	Push
 *    (b)	Pop
 *    (c)	Clear
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <class T>
class Stack
{
protected:
  int tos, size;
  T arr[MAX_SIZE];

public:
  Stack(int size = 30)
  {
    this->tos = -1;
    this->size = size;
  }

  bool push(T ele)
  {
    if (this->tos >= (this->size - 1))
    {
      cerr << "ERROR: Stack Overflow\n";
      return false;
    }
    this->arr[++(this->tos)] = ele;
    return true;
  }

  T pop()
  {
    if (this->isEmpty())
    {
      cout << "ERROR: Stack Underflow\n";
      return (T)(NULL);
    }
    return this->arr[(this->tos)--];
  }

  T top()
  {
    if (this->isEmpty())
    {
      cout << "Stack Empty";
      return (T)(NULL);
    }
    return this->arr[this->tos];
  }

  bool isEmpty()
  {
    return this->tos == -1;
  }

  void clear()
  {
    while (!this->isEmpty())
      this->pop();
  }

  void display()
  {
    int i;
    for (i = 0; i < this->tos; i++)
      cout << this->arr[i] << " <- ";
    cout << this->arr[i] << endl;
    return;
  }
};
