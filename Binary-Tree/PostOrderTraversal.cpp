#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *constructBinaryTree(Node *root)
{
    int data;
    cout << "Enter a data:";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *newNode = new Node(data);
    cout << "Enter data for the left of " << data << endl;
    newNode->left = constructBinaryTree(newNode->left);

    cout << "Enter data for the right of " << data << endl;
    newNode->right = constructBinaryTree(newNode->right);

    return newNode;
}

void printInOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    // print left subtree
    printInOrderTraversal(node->left);
    // print right subtree
    printInOrderTraversal(node->right);
    // print middle node
    cout << node->data << " ";
}

int main()
{
    Node *root = NULL;
    root = constructBinaryTree(root);
    printInOrderTraversal(root);
}
