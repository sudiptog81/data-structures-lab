/**
 *  WAP to add two large integers using stack.
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "stack.hpp"
#include <cstring>
#include <string>
#define MAX_STRLEN 256

class BigInt {
protected:
  int size;
  Stack<int> *stack;

public:
  BigInt(int size = 10) {
    this->size = size;
    this->stack = new Stack<int>(size);
  }

  ~BigInt() { delete this->stack; }

  void setInteger(string &str) {
    for (int i = 0; i < str.length(); i++)
      this->stack->push(str[i] - '0');
    return;
  }

  void displayInteger() {
    while (!this->stack->isEmpty())
      cout << this->stack->pop();
    return;
  }

  static void add(BigInt &num1, BigInt &num2, BigInt &res) {
    int i = num1.size, j = num2.size;
    int temp, num1Pop, num2Pop, carry = 0;
    while (num1.size > num2.size ? !num1.stack->isEmpty()
                                 : !num2.stack->isEmpty()) {
      num1Pop = num1.stack->isEmpty() ? 0 : num1.stack->pop();
      num2Pop = num2.stack->isEmpty() ? 0 : num2.stack->pop();
      temp = carry + num1Pop + num2Pop;
      if (temp >= 10) {
        carry = temp / 10;
        temp = temp % 10;
      }
      res.stack->push(temp);
    }
    if (carry)
      res.stack->push(carry);
  }
};

int main(void) {
  string num1, num2;

  cout << "Enter BigInt 1: ";
  cin >> num1;

  cout << "Enter BigInt 2: ";
  cin >> num2;

  BigInt bigInt1(num1.length()), bigInt2(num2.length()),
      bigIntRes(num1.length() + num2.length());

  bigInt1.setInteger(num1);
  bigInt2.setInteger(num2);

  BigInt::add(bigInt1, bigInt2, bigIntRes);

  cout << "Sum: ";
  bigIntRes.displayInteger();
  cout << endl;

  return 0;
}
