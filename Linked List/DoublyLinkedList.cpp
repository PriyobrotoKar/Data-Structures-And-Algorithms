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

void insertAtMiddle(int data, int pos, Node *&head)
{
    if (pos == 1)
    {
        insertAtHead(data, head);
    }
    else
    {
        Node *node = new Node(data);
        Node *temp = head;
        int cnt = 1;
        while (temp && cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (cnt + 1 == pos && temp)
        {
            node->next = temp->next;
            temp->next = node;
            cout << "Node inserted successfully at position " << pos << "-> " << data << endl;
        }
        else
        {
            cout << "InsertAtMiddle : Entered Position is out of bounds" << endl;
            exit(1);
        }
    }
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

void deleteNode(int pos, Node *&head)
{
    if (pos == 1)
    {
        // Deleting head
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // Deleting any other node
        int cnt = 1;
        Node *currNode = head;
        Node *prevNode = NULL;
        while (cnt < pos && currNode)
        {
            prevNode = currNode;
            currNode = currNode->next;
            cnt++;
        }
        if (cnt == pos && currNode)
        {
            prevNode->next = currNode->next;
            currNode->next = NULL;
            delete currNode;
        }
        else
        {
            cout << "DeleteNode : Entered position is out of bounds" << endl;
            exit(1);
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
    insertAtMiddle(5, 1, head);
    insertAtMiddle(13, 3, head);
    insertAtMiddle(20, 8, head);
    printNodes(head);
    deleteNode(10, head);
    printNodes(head);
}