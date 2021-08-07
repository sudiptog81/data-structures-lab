/**
 * Given a list of N elements, which follows no particular 
 * arrangement, you are required to search an element x in 
 * the list. The list is stored using array data structure.
 * If the search is successful, the output should be the 
 * index at which the element occurs, otherwise returns -1 
 * to indicate that the element is not present in the list. 
 * Assume that the elements of the list are all distinct. 
 * Write a program to perform the desired task.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <class T>
int linearSearch(T *arr, int size, T el)
{
  for (int i = 0; i < size; i++)
    if (arr[i] == el)
      return i;
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

  res = linearSearch<int>(arr, N, el);

  if (res != -1)
    cout << "FOUND: Element found at index "
         << res << endl;
  else
    cout << "NOT FOUND: Element not found in array"
         << endl;

  return 0;
}
