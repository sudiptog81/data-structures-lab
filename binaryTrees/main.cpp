/**
 *  Write a menu driven program to implement the following operations 
 *  in a Binary Search Tree:
 *    (a) Insertion
 *    (b) Searching a node
 *    (c) Display its preorder, postorder and inorder traversals. (recursive)
 *    (d) Display its preorder, postorder and inorder traversals. (iterative)
 *    (e) Display level-by-level traversal. (BFS)
 *    (f) Create a mirror image of tree
 *    (g) Count the non-leaf, leaf and total number of nodes  
 *    (h) Search for an element x in the BST and change its value to y 
 *        and then place the node with value y at its appropriate position
 *    (i) Display height of tree
 *    (j) Perform deletion by merging
 *    (k) Perform deletion by copying
 * 
 *  Written by Sudipto Ghosh for the University of Delhi
 */

#include "stack.hpp"
#include "queue.hpp"

void getch();
void clrscr();

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
  Stack<Node<int> *> stack;
  Queue<Node<int> *> queue;
  int countLeaf, countNonLeaf;

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

  Node<int> *search(int key, Node<int> *root)
  {
    if (root == nullptr || root->data == key)
      return root;
    if (root->data < key)
      return search(key, root->right);
    return search(key, root->left);
  }

  void inOrderRecursive(Node<int> *root)
  {
    if (root != nullptr)
    {
      inOrderRecursive(root->left);
      cout << root->data << " ";
      inOrderRecursive(root->right);
    }
  }

  void preOrderRecursive(Node<int> *root)
  {
    if (root != nullptr)
    {
      cout << root->data << " ";
      preOrderRecursive(root->left);
      preOrderRecursive(root->right);
    }
  }

  void postOrderRecursive(Node<int> *root)
  {
    if (root != nullptr)
    {
      postOrderRecursive(root->left);
      postOrderRecursive(root->right);
      cout << root->data << " ";
    }
  }

  void inOrderIterative()
  {
    Node<int> *current = root;

    while (current != nullptr ||
           stack.isEmpty() == false)
    {
      while (current != nullptr)
      {
        stack.push(current);
        current = current->left;
      }
      current = stack.pop();
      cout << current->data << " ";
      current = current->right;
    }
  }

  void preOrderIterative()
  {
    Node<int> *node, *temp = root;
    if (temp == nullptr)
      return;
    stack.push(temp);
    while (!stack.isEmpty())
    {
      node = stack.pop();
      cout << node->data << " ";
      if (node->right)
        stack.push(node->right);
      if (node->left)
        stack.push(node->left);
    }
  }

  void postOrderIterative()
  {
    Node<int> *temp = root;
    if (temp == nullptr)
      return;
    do
    {
      while (temp)
      {
        if (temp->right)
          stack.push(temp->right);
        stack.push(temp);
        temp = temp->left;
      }
      temp = stack.pop();
      if (temp->right && !stack.isEmpty() &&
          stack.top() == temp->right)
      {
        stack.pop();
        stack.push(temp);
        temp = temp->right;
      }
      else
      {
        cout << temp->data << " ";
        temp = nullptr;
      }
    } while (!stack.isEmpty());
  }

  void levelByLevelTraversal()
  {
    Node<int> *current = root;

    if (current == nullptr)
      return;

    queue.enqueue(current);
    while (!queue.isEmpty())
    {
      current = queue.dequeue();
      cout << current->data << " ";
      if (current->left)
        queue.enqueue(current->left);
      if (current->right)
        queue.enqueue(current->right);
    }

    cout << endl;
  }

  void countNodes(Node<int> *current)
  {
    if (current == nullptr)
      return;
    if (current->left != nullptr ||
        current->right != nullptr)
      countNonLeaf++;
    if (current->left == nullptr &&
        current->right == nullptr)
      countLeaf++;
    countNodes(current->left);
    countNodes(current->right);
  }
};

int main(void)
{
  int choice, data;
  BinarySearchTree tree;

  do
  {
    cout << "      MENU      \n"
         << "================\n"
         << "(1) Insertion\n"
         << "(2) Searching a node\n"
         << "(3) Display its preorder, postorder and inorder traversals. (recursive)\n"
         << "(4) Display its preorder, postorder and inorder traversals. (iterative)\n"
         << "(5) Display level-by-level traversal. (BFS)\n"
         << "(6) Create a mirror image of tree\n"
         << "(7) Count the non-leaf, leaf and total number of nodes  \n"
         << "(8) Search for an element x in the BST and change its value to y \n"
         << "    and then place the node with value y at its appropriate position\n"
         << "(9) Display height of tree\n"
         << "(10) Perform deletion by merging\n"
         << "(11) Perform deletion by copying\n"
         << "(0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "\nEnter Node Data: ";
      cin >> data;
      tree.insert(data, tree.root);
      break;
    case 2:
      cout << "\nEnter Search Data: ";
      cin >> data;
      cout << "Search Result: ";
      if (tree.search(data, tree.root))
        cout << "Found";
      else
        cout << "Not Found";
      cout << endl;
      break;
    case 3:
      cout << endl;
      cout << "In-Order Recursive Traversal: ";
      tree.inOrderRecursive(tree.root);
      cout << endl;
      cout << "Pre-Order Recursive Traversal: ";
      tree.preOrderRecursive(tree.root);
      cout << endl;
      cout << "Post-Order Recursive Traversal: ";
      tree.postOrderRecursive(tree.root);
      cout << endl;
      break;
    case 4:
      cout << endl;
      cout << "In-Order Iterative Traversal: ";
      tree.inOrderIterative();
      cout << endl;
      cout << "Pre-Order Iterative Traversal: ";
      tree.preOrderIterative();
      cout << endl;
      cout << "Post-Order Iterative Traversal: ";
      tree.postOrderIterative();
      cout << endl;
      break;
    case 5:
      cout << endl;
      cout << "Level-by-level Traversal: \n";
      tree.levelByLevelTraversal();
      break;
    case 7:
      tree.countLeaf = tree.countNonLeaf = 0;
      tree.countNodes(tree.root);
      cout << endl;
      cout << "Leaf Nodes: "
           << tree.countLeaf << endl;
      cout << "Non-Leaf Nodes: "
           << tree.countNonLeaf << endl;
      cout << "Total Nodes: "
           << tree.countNonLeaf +
                  tree.countLeaf
           << endl;
      break;
    case 0:
    default:
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
