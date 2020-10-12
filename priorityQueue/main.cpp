#include <iostream>

using namespace std;

class PriorityQueue
{
  int heap[20];
  int heapSize;

  PriorityQueue(int n)
  {
    heapSize = n;
  }

  int parent(int i)
  {
    return i / 2 + 1;
  }

  int left(int i)
  {
    return 2 * i + 1;
  }

  int right(int i)
  {
    return 2 * i + 2;
  }

  void maxHeapify(int i)
  {
    int largest;
    int l = left(i);
    int r = right(i);
    if (l <= heapSize && heap[l] > heap[i])
    {
      largest = l;
    }
    else
    {
      largest = i;
    }
    // TODO
  }
};

int main()
{

  return 0;
}
