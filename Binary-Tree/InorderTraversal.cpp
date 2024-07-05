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

void printPostOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    // print left subtree
    printPostOrderTraversal(node->left);
    // print right subtree
    printPostOrderTraversal(node->right);
    // print middle node
    cout << node->data << " ";
}

int main()
{
    Node *root = NULL;
    // 1  3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = constructBinaryTree(root);
    printPostOrderTraversal(root);
}
