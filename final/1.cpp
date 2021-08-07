/**
 * Insert elements in an empty binary search tree. 
 * Print only those nodes that are right child of 
 * its immediate parent. (Any order) 
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
  T data;
  Node *left, *right;
  Node()
  {
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree
{
public:
  Node<int> *root;

  BinarySearchTree()
  {
    root = nullptr;
  }

  void insert(int data, Node<int> *current)
  {
    Node<int> *temp;
    if (root == nullptr)
    {
      root = new Node<int>;
      root->data = data;
      root->left = root->right = nullptr;
    }
    else
    {
      if ((data < current->data) &&
          (current->left == nullptr))
      {
        temp = new Node<int>;
        temp->data = data;
        temp->left = temp->right = nullptr;
        current->left = temp;
      }
      else if ((data >= current->data) &&
               (current->right == nullptr))
      {
        temp = new Node<int>;
        temp->data = data;
        temp->left = temp->right = nullptr;
        current->right = temp;
      }
      else
      {
        if (data < current->data)
          insert(data, current->left);
        else
          insert(data, current->right);
      }
    }
  }

  void printRightNodes(Node<int> *root)
  {
    if (root != nullptr)
    {
      printRightNodes(root->left);
      printRightNodes(root->right);
      if (root->right != nullptr)
        cout << root->right->data << " ";
    }
  }
};

int main(void)
{
  int n, el;
  BinarySearchTree tree;
  cout << "Enter Number of Nodes to Insert: ";
  cin >> n;
  cout << "Enter Elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> el;
    tree.insert(el, tree.root);
  }
  cout << "Nodes that are right child of their immediate parent: ";
  tree.printRightNodes(tree.root);
  cout << endl;
  return 0;
}
