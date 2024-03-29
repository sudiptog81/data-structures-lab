/**
 * Given a list of N elements, which is sorted in ascending
 * order, you are required to search an element x in the list.
 * The list is stored using array data structure. If the search
 * is successful, the output should be the index at which 
 * the element occurs, otherwise returns -1 to indicate that 
 * the element is not present in the list. Assume that the 
 * elements of the list are all distinct. Write a program to 
 * perform the desired task.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <class T>
int binarySearch(T *arr, int left, int right, T el)
{
  if (right >= left)
  {
    int mid = (right + left) / 2;
    if (arr[mid] == el)
      return mid;
    if (arr[mid] > el)
      return binarySearch(arr, left, mid - 1, el);
    return binarySearch(arr, mid + 1, right, el);
  }
  return -1;
}

int main(void)
{
  int ch = 1, el, res, N, arr[MAX_SIZE];

  cout << "Enter Number of Elements: ";
  cin >> N;

  cout << "Enter Array Elements: ";
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  cout << "Enter Search Element: ";
  cin >> el;

  res = binarySearch<int>(arr, 0, N - 1, el);

  if (res != -1)
    cout << "FOUND: Element found at index "
         << res << endl;
  else
    cout << "NOT FOUND: Element not found in array"
         << endl;

  return 0;
}
