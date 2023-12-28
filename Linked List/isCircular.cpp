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

bool isCircular(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == head)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertAtTailCir(int data, Node *head)
{
    Node *node = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = node;
        node->next = head;
    }
    else
    {
        // Traverse to the last node
        while (temp->next != head && temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = node;
        node->next = head;
    }
}

void printNodeCir(Node *head)
{
    Node *temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
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

int main()
{
    Node *newNode = new Node(3);
    Node *head = newNode;
    insertAtTailCir(5, head);
    insertAtTailCir(9, head);
    insertAtTailCir(12, head);
    printNodeCir(head);
    // insertAtTail(5, head);
    // insertAtTail(9, head);
    // insertAtTail(12, head);
    // printNode(head);
    cout << isCircular(head) << endl;
}