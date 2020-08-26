/**
 *  WAP to evaluate postfix expression using stack.
 *
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "stack.hpp"
#include <cstring>
#include <string>
#define MAX_STRLEN 256

class PostfixEvaluator {
protected:
  Stack<int> stack;

public:
  int evaluate(string &str) {
    int val1, val2, temp;
    int size = str.length();
    for (int i = 0; i < size; ++i) {
      if (str[i] == ' ')
        continue;
      else if (isdigit(str[i])) {
        temp = 0;
        while (isdigit(str[i]))
          temp = temp * 10 + (int)(str[i++] - '0');
        i--;
        this->stack.push(temp);
      } else {
        val1 = this->stack.pop();
        val2 = this->stack.pop();
        switch (str[i]) {
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
        case '%':
          this->stack.push(val2 % val1);
          break;
        }
      }
    }
    return this->stack.pop();
  }
};

int main(void) {
  string str;
  PostfixEvaluator eval;
  cout << "Enter Postfix Expression: ";
  getline(cin, str);
  cout << "Value of Expression: " << eval.evaluate(str) << endl;
  return 0;
}
