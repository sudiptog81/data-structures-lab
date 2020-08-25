/**
 *  WAP to add two large integers using stack.
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <string>
#include <cstring>
#include "stack.hpp"
#define MAX_STRLEN 256

class BigInt
{
protected:
  int size;
  Stack<int> *stack;

public:
  BigInt(int size = 10)
  {
    this->size = size;
    this->stack = new Stack<int>(size);
  }

  ~BigInt()
  {
    delete this->stack;
  }

  void setInteger(string &str)
  {
    for (int i = 0; i < str.length(); i++)
      this->stack->push(str[i] - '0');
    return;
  }

  void displayInteger()
  {
    while (!this->stack->isEmpty())
      cout << this->stack->pop();
    return;
  }

  static void add(BigInt &num1, BigInt &num2, BigInt &res)
  {
    int i = num1.size, j = num2.size;
    int temp, carry = 0;
    int max = (i >= j ? i : j);
    while (max > 0)
    {
      carry = 0;
      temp = carry + num1.stack->pop() + num2.stack->pop();
      if (temp >= 10)
      {
        carry = 1;
        temp %= 10;
      }
      res.stack->push(temp);
      --max;
    }
  }
};

int main(void)
{
  string num1, num2;

  cout << "Enter BigInt 1: ";
  cin >> num1;

  cout << "Enter BigInt 2: ";
  cin >> num2;

  BigInt bigInt1(num1.length()),
      bigInt2(num2.length()),
      bigIntRes(num1.length() + num2.length());

  bigInt1.setInteger(num1);
  bigInt2.setInteger(num2);

  BigInt::add(bigInt1, bigInt2, bigIntRes);

  cout << "Sum: ";
  bigIntRes.displayInteger();
  cout << endl;

  return 0;
}
