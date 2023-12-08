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

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr;
    while (curr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        }
    return prev;
}

int main()
{
    Node *newNode = new Node(3);
    Node *head = newNode;
    insertAtTail(5, head);
    printNode(head);
    printNode(reverseLinkedList(head));
}