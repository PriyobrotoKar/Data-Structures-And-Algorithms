#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void printNode(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        temp->next ? cout << temp->data << "->" : cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(int data, Node *head)
{
    Node *node = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    delete temp;
}

Node *findMiddleNode(Node *&head)
{
    if (head->next == NULL)
    {
        return head;
    }

    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // cout << slow->data << endl;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    Node *newNode = new Node(5);
    Node *head = newNode;
    insertAtTail(8, head);
    insertAtTail(10, head);
    insertAtTail(15, head);
    printNode(head);
    cout << "Middle Node : " << findMiddleNode(head)->data << endl;
}