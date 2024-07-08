#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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

int getHeight(Node *node, int height)
{
    if (!node)
    {
        return height;
    }

    int leftHeight = getHeight(node->left, height);
    int rightHeight = getHeight(node->right, height);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = NULL;
    // 1  3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = constructBinaryTree(root);
    cout << "Height of the tree :" << getHeight(root, 0) << endl;
}
