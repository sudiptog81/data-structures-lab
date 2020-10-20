/**
 * Write a menu driven program to implement Min_Priority_Queue
 * that supports the following operations:
 *``  (a) Heap-Decrease_Key
 *``  (b) Min_Heap_Insert
 *``  (c) Heap_Minimum
 *``  (d) Heap_Extract_Min
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_SIZE 20

using namespace std;

void getch();
void clrscr();

class Heap
{
public:
  int *heap;
  int heapSize;

  Heap(int *&A, int n)
  {
    heap = A;
    heapSize = n;
  }

  int parent(int i)
  {
    return (i - 1) / 2;
  }

  int left(int i)
  {
    return 2 * i + 1;
  }

  int right(int i)
  {
    return 2 * i + 2;
  }

  void minHeapify(int *&A, int n, int i)
  {
    int temp;
    int least;
    int l = left(i);
    int r = right(i);
    if (l < n && A[l] <= A[i])
    {
      least = l;
    }
    else
    {
      least = i;
    }
    if (r < n && A[r] <= A[least])
    {
      least = r;
    }
    if (least != i)
    {
      temp = A[i];
      A[i] = A[least];
      A[least] = temp;
      minHeapify(A, n, least);
    }
  }

  void buildMinHeap()
  {
    for (int i = heapSize / 2; i >= 0; i--)
      minHeapify(heap, heapSize, i);
  }
};

class MinPriorityQueue
{
public:
  Heap *heap;

  MinPriorityQueue(int A[], int n)
  {
    heap = new Heap(A, n);
    heap->buildMinHeap();
  }

  ~MinPriorityQueue()
  {
    delete heap;
  }

  int size()
  {
    return heap->heapSize;
  }

  void display()
  {
    if (heap->heapSize == 0)
    {
      cerr << "ERROR: Heap Empty";
      return;
    }
    for (int i = 0; i < heap->heapSize; i++)
      cout << heap->heap[i] << " ";
  }

  void heapDecreaseKey(int i, int key)
  {
    int temp;
    if (key >= heap->heap[i])
    {
      cerr << "ERROR: New Key is larger than Existing Key";
      return;
    }
    heap->heap[i] = key;
    while (i > 0 && heap->heap[heap->parent(i)] >= heap->heap[i])
    {
      temp = heap->heap[heap->parent(i)];
      heap->heap[heap->parent(i)] = heap->heap[i];
      heap->heap[i] = temp;
      i = heap->parent(i);
    }
  }

  void minHeapInsert(int key)
  {
    heap->heapSize++;
    heap->heap[heap->heapSize - 1] = INT8_MAX;
    heapDecreaseKey(heap->heapSize - 1, key);
  }

  int heapMinimum()
  {
    if (heap->heapSize == 0)
    {
      cerr << "ERROR: Heap Empty";
      return -1;
    }
    return heap->heap[0];
  }

  int heapExtractMin()
  {
    if (heap->heapSize < 0)
    {
      cerr << "ERROR: Heap Underflow";
      return -1;
    }
    else if (heap->heapSize == 0)
    {
      cerr << "ERROR: Heap Empty";
      return -1;
    }
    int min = heap->heap[0];
    heap->heap[0] = heap->heap[heap->heapSize];
    heap->minHeapify(heap->heap, --heap->heapSize, 0);
    return min;
  }
};

int main(void)
{
  int idx, key;
  int n, choice = 1, A[MAX_SIZE] = {0};

  cout << "Initial Data\n============\n";
  cout << "Enter Number of Nodes: ";
  cin >> n;
  cout << "Enter Keys of the Nodes: ";
  for (int i = 0; i < n; i++)
    cin >> A[i];
  clrscr();

  MinPriorityQueue queue(A, n);

  do
  {
    cout << "\t   Min Priority Queue\n"
         << "===========================================\n"
         << "  (1) HeapDecreaseKey  (2) MinHeapInsert\n"
         << "  (3) HeapMinimum      (4) HeapExtractMin\n"
         << "  (5) Display          (0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
      cout << endl;
      cout << "Enter Position: ";
      cin >> idx;
      cout << "Enter New Key: ";
      cin >> key;
      queue.heapDecreaseKey(idx - 1, key);
      cout << endl;
      break;
    case 2:
      cout << endl;
      cout << "Enter Key: ";
      cin >> key;
      queue.minHeapInsert(key);
      break;
    case 3:
      cout << endl;
      key = queue.heapMinimum();
      if (key != -1)
        cout << "Heap Minimum: "
             << key << endl;
      break;
    case 4:
      cout << endl;
      key = queue.heapExtractMin();
      if (key != -1)
      {
        cout << "After Heap Extract Min: ";
        queue.display();
        cout << endl;
      }
      break;
    case 5:
      cout << endl;
      queue.display();
      cout << endl;
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
