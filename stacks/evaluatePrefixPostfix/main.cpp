/**
 *  WAP to evaluate postfix expression using stack.
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

// main.cpp
#include "stack.hpp"
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#define MAX_STRLEN 256

class PostfixEvaluator
{
protected:
  Stack<float> stack;

public:
  float evaluate(string &str)
  {
    float val1, val2, temp;
    int size = str.length();
    for (int i = 0; i < size; ++i)
    {
      if (str[i] == ' ')
        continue;
      else if (isdigit(str[i]))
      {
        temp = 0;
        while (isdigit(str[i]))
          temp = temp * 10 + (int)(str[i++] - '0');
        i--;
        this->stack.push(temp);
      }
      else
      {
        val1 = this->stack.pop();
        val2 = this->stack.pop();
        switch (str[i])
        {
        case '^':
          this->stack.push(pow(val2, val1));
          break;
        case '+':
          this->stack.push(val2 + val1);
          break;
        case '-':
          this->stack.push(val2 - val1);
          break;
        case '*':
          this->stack.push(val2 * val1);
          break;
        case '/':
          this->stack.push(val2 / val1);
          break;
          // case '%':
          //   this->stack.push(val2 % val1);
          //   break;
        }
      }
    }
    return this->stack.pop();
  }
};

class PrefixEvaluator
{
private:
  void swap(char &xp, char &yp)
  {
    char temp = xp;
    xp = yp;
    yp = temp;
  }

protected:
  Stack<int> stack;

public:
  int evaluate(string &str)
  {
    string strTemp;
    int val1, val2, temp;
    int size = str.length();
    // parse expression in a reverse fashion
    for (int i = size - 1; i >= 0; i--)
    {
      if (str[i] == ' ')
        continue;
      else if (isdigit(str[i]))
      {
        strTemp = "";
        while (isdigit(str[i]))
          strTemp.append(string(1, str[i--]));
        i++;
        for (int i = 0; i < strTemp.length() / 2; i++)
          swap(strTemp[i], strTemp[strTemp.length() - i - 1]);
        temp = atoi(strTemp.c_str());
        this->stack.push(temp);
      }
      else
      {
        val1 = this->stack.pop();
        val2 = this->stack.pop();
        switch (str[i])
        {
        case '+':
          this->stack.push(val1 + val2);
          break;
        case '-':
          this->stack.push(val1 - val2);
          break;
        case '*':
          this->stack.push(val1 * val2);
          break;
        case '/':
          this->stack.push(val1 / val2);
          break;
        case '%':
          this->stack.push(val1 % val2);
          break;
        }
      }
    }
    return this->stack.pop();
  }
};

int main(void)
{
  string str;
  PrefixEvaluator preEval;
  PostfixEvaluator postEval;
  cout << "Enter Prefix Expression: ";
  getline(cin, str);
  cout << "Value of Expression: " << preEval.evaluate(str) << endl;
  cout << endl;
  cout << "Enter Postfix Expression: ";
  getline(cin, str);
  cout << "Value of Expression: " << postEval.evaluate(str) << endl;
  return 0;
}
