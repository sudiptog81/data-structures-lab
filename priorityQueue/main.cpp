#include <iostream>

using namespace std;

int heap[20];
int heapSize;

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

void maxHeapify(int *&A, int n, int i)
{
  int temp;
  int largest;
  int l = left(i);
  int r = right(i);
  if (l <= n && A[l] > A[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if (r <= n && A[r] > A[largest])
  {
    largest = r;
  }
  if (largest != i)
  {
    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;

    maxHeapify(A, n, largest);
  }
}

void buildMaxHeapify(int A[], int n)
{
  for (int i = n / 2; i >= 0; i--)
    maxHeapify(A, n, i);
}

int main()
{
  int A[20];

  for (int i = 0; i < 10; i++)
    cin >> A[i];

  buildMaxHeapify(A, 10);

  for (int i = 0; i < 10; i++)
    cout << A[i] << " ";

  return 0;
}
