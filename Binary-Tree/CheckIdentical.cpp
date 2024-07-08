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

bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (!root1 && root2)
    {
        return false;
    }

    bool isIdenticalNode = root1->data == root2->data;
    bool isLeftTreeIdentical = isIdentical(root1->left, root2->left);
    bool isRightTreeIdentical = isIdentical(root1->right, root2->right);

    if (isIdenticalNode == isLeftTreeIdentical == isRightTreeIdentical)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    // 1  3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root1 = constructBinaryTree(root1);
    // 1  3 7 -1 -1 11 -1 -1 5 11 -1 -1 -1
    root2 = constructBinaryTree(root2);
    cout << (isIdentical(root1, root2) ? "Identical Trees" : "Non-Identical Trees") << endl;
}
