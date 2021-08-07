/**
 * WAP to perform sorting in descending order that runs in 
 * O(n^2) in all cases. 
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_SIZE 100

using namespace std;

int *selectionSort(int *arr, int n)
{
  int max, temp;
  for (int i = 0; i < n - 1; i++)
  {
    max = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[max])
        max = j;
    temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
  return arr;
}

int main(void)
{
  int n;
  int *arr = new int[MAX_SIZE];
  cout << "Enter No. of Elements: ";
  cin >> n;
  cout << "Enter Elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  arr = selectionSort(arr, n);
  cout << "Sorted Array (Descending): ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  delete[] arr;
  return 0;
}
