/**
 *  Delimiter Matcher
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include <fstream>
#include <cstring>
#include "stack.hpp"
#define MAX_STRLEN 256

using namespace std;

void getch();
void clrscr();

class DelimiterMatcher
{
protected:
  Stack<char> stack;

public:
  bool isMatched(char *str)
  {
    this->stack.clear();
    if (!str)
      return true;
    char ch, temp, temp1;
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
      if (str[i] == '(' ||
          str[i] == '[' ||
          str[i] == '{')
      {
        this->stack.push(str[i]);
        continue;
      }
      switch (str[i])
      {
      case ')':
        ch = this->stack.pop();
        if (ch == '{' || ch == '[')
          return false;
        break;
      case '}':
        ch = this->stack.pop();
        if (ch == '(' || ch == '[')
          return false;
        break;
      case ']':
        ch = this->stack.pop();
        if (ch == '(' || ch == '{')
          return false;
        break;
      }
    }
    return (this->stack.isEmpty());
  }

  bool isMatchedFile(char *filename)
  {
    this->stack.clear();
    int i = 0;
    ifstream fd(filename);
    if (!fd)
    {
      cout << "ERROR: Unable to open file\n";
      return false;
    }
    char str[MAX_STRLEN] = {'\0'};
    while (!fd.eof() && i < MAX_STRLEN)
      fd.get(str[i++]);
    fd.close();
    return isMatched(str);
  }
};

int main(void)
{
  int choice;
  char str[MAX_STRLEN] = {'\0'};
  DelimiterMatcher matcher;
  do
  {
    cout << "\tDelimiter Matcher\n"
         << "===================================\n"
         << "  (1) Read Expression\n"
         << "  (2) Read Contents from File\n\n"
         << "Enter a choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter Expression: ";
      cin >> str;
      if (matcher.isMatched(str))
        cout << "\nSUCCESS: All Delimiters are Matched\n";
      else
        cout << "\nFAILURE: Delimiters are Not Matched\n";
      break;
    case 2:
      cout << "Enter Filename: ";
      cin >> str;
      if (matcher.isMatchedFile(str))
        cout << "\nSUCCESS: All Delimiters are Matched\n";
      else
        cout << "\nFAILURE: Delimiters are Not Matched\n";
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
