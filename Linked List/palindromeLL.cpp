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

bool isPalindrome(Node *&head)
{
    Node *start = head;
    Node *end = head;

    while (end->next)
    {
        end = end->next;
    }

    while (start->next != end->next && end->next != start)
    {
        if (start->data != end->data)
        {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main()
{
    Node *newNode = new Node(1);
    Node *head = newNode;
    insertAtTail(2, head);
    insertAtTail(3, head);
    insertAtTail(3, head);
    insertAtTail(2, head);
    insertAtTail(1, head);
    printNodes(head);
    cout << isPalindrome(head) << endl;
}