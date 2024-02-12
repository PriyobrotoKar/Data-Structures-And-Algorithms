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
    cout << "Node inserted successfully at head " << data << endl;
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
        cout << "Node inserted successfully at position " << pos << " -> " << data << endl;
    }
    else
    {
        cout << "InsertAtMiddle : Entered Position is out of bounds" << endl;
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
            cout << "Node inserted successfully at tail " << data << endl;
            break;
        }
        temp = temp->next;
    }
}

void deleteNode(int pos, Node *&head)
{
    int value;
    // deleting the first node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        value = temp->data;
        temp->next = NULL;
        delete temp;
    }
    // deleting any middle or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        value = curr->data;
        curr->next = NULL;
        delete curr;
    }
    cout << "Node deleted successfully at position " << pos << " -> " << value << endl;
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

void removeDuplicates(Node *&head)
{
    Node *curr = head->next;
    Node *prev = head;

    while (curr != NULL)
    {
        if (curr->data != prev->data)
        {
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev->next;
        }
    }
}

int main()
{
    Node *node1 = new Node(1);

    Node *head = node1;

    insertAtTail(2, head);
    insertAtTail(2, head);
    insertAtTail(3, head);
    insertAtTail(3, head);
    insertAtTail(3, head);
    insertAtTail(4, head);
    printNodes(head);
    removeDuplicates(head);
    printNodes(head);
}