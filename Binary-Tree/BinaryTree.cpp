#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *constructBinaryTree(Node *root)
{
    Node *newNode = new Node();
    int data;
    cout << "Enter a data:";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    newNode->data = data;
    cout << "Enter data for the left of " << data << endl;
    newNode->left = constructBinaryTree(newNode->left);

    cout << "Enter data for the right of " << data << endl;
    newNode->right = constructBinaryTree(newNode->right);

    return newNode;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();

        if (front == NULL)
        {
            cout << endl;
            q.pop();
            continue;
        }
        q.pop();
        if (q.empty() || q.front() != NULL)
        {
            q.push(NULL);
        }
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
        cout << front->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 4 -1 -1 9 -1 -1 5 -1 -1
    root = constructBinaryTree(root);
    cout << "Printing level order traversal:" << endl;
    levelOrderTraversal(root);
}
