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

pair<bool, int> isBalanced(Node *node)
{
    if (!node)
    {
        return {true, 0};
    }

    pair<bool, int> leftAns = isBalanced(node->left);
    pair<bool, int> rightAns = isBalanced(node->right);

    bool isBalanced = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool, int> ans;
    if (leftAns.first && rightAns.first && isBalanced)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    ans.second = max(leftAns.second, rightAns.second) + 1;

    return ans;
}

int main()
{
    Node *root = NULL;
    // 1  3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = constructBinaryTree(root);
    cout << (isBalanced(root).first ? "Balanced Tree" : "Unbalanced Tree") << endl;
}
