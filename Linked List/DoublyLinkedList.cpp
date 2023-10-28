#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(int data, Node *&head)
{
    Node *node = new Node(data);
    node->next = head;
    head->prev = node;
    head = node;
    cout << "Node inserted successfully at head -> " << data << endl;
}

void insertAtMiddle(int data, Node *&head)
{
}
void insertAtTail(int data, Node *&head)
{
    Node *node = new Node(data);
    Node *temp = head;
    while (temp)
    {
        if (!temp->next)
        {
            temp->next = node;
            node->prev = temp;
            cout << "Node inserted successfully at tail -> " << data << endl;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void printNodes(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        (temp->next) ? cout << temp->data << " <-> " : cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *newNode = new Node(10);
    Node *head = newNode;
    insertAtHead(5, head);
    insertAtHead(15, head);
    insertAtHead(90, head);
    insertAtTail(60, head);
    insertAtTail(30, head);
    printNodes(head);
}