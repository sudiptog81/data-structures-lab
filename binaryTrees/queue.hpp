/**
 *  Perform the following Queue operations using Linear Array
 *  implementation (Use Templates):
 *    (a)	Enqueue
 *    (b)	Dequeue
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

// queue.hpp
#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <class T>
class Queue
{
protected:
  T arr[MAX_SIZE];
  int front, rear, size;

public:
  Queue(int size = 100)
  {
    this->front = -1;
    this->rear = -1;
    this->size = size;
  }

  bool enqueue(T ele)
  {
    if (this->rear >= (this->size - 1))
    {
      cerr << "ERROR: Queue Filled\n";
      return false;
    }
    else if (this->isEmpty())
    {
      this->rear++;
      this->front++;
      this->arr[this->front] = ele;
    }
    else
      this->arr[++(this->rear)] = ele;
    return true;
  }

  T dequeue()
  {
    if (this->front >= this->size)
    {
      cout << "ERROR: Queue Finished\n";
      return (T)(NULL);
    }
    else if (this->isEmpty())
    {
      cout << "ERROR: Queue Empty\n";
      return (T)(NULL);
    }
    else if (this->front == this->rear)
    {
      T temp = this->arr[this->front];
      this->clear();
      return temp;
    }
    return this->arr[(this->front)++];
  }

  T frontEl()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return (T)(NULL);
    }
    return this->arr[this->front];
  }

  bool isEmpty()
  {
    return this->front == -1;
  }

  void clear()
  {
    this->front = this->rear = -1;
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
      return;
    }
    int i;
    for (i = this->front; i < this->rear; i++)
      cout << this->arr[i] << " <- ";
    cout << this->arr[i] << endl;
    return;
  }
};
