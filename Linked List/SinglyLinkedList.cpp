#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(int data, Node *&head)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtMiddle(int data, int pos, Node *&head)
{
    int currPos = 1;
    Node *temp = head;

    while (temp && currPos < pos - 1)
    {
        currPos++;
        temp = temp->next;
    }
    if (currPos + 1 == pos && temp)
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        cout << "Entered Position is out of bounds" << endl;
        exit(1);
    }
}

void insertAtTail(int data, Node *&head)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp)
    {
        if (!temp->next)
        {
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

void printNodes(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        (temp->next) ? cout << temp->data << " -> " : cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;

    insertAtHead(20, head);
    insertAtHead(30, head);
    insertAtHead(40, head);
    insertAtTail(50, head);
    insertAtTail(60, head);
    insertAtTail(70, head);
    insertAtMiddle(80, 9, head);
    printNodes(head);
}