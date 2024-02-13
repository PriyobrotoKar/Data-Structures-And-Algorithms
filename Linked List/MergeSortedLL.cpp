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

Node *insertAtTail(int data, Node *&head)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    Node *tail = head;
    while (temp)
    {
        if (!temp->next)
        {
            temp->next = newNode;
            cout << "Node inserted successfully at tail " << data << endl;
            tail = temp->next;
            break;
        }
        temp = temp->next;
    }
    return tail;
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

Node *mergeSortedLL(Node *&head1, Node *&head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }

    Node *curr = head1->next;
    Node *prev = head1;

    while (curr && head2)
    {
        if (head2->data >= prev->data && head2->data <= curr->data)
        {
            prev->next = head2;
            Node *temp = head2->next;
            head2->next = curr;
            prev = prev->next;
            head2 = temp;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }

    while (head2)
    {
        prev->next = head2;
        head2 = head2->next;
    }
    return head1;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    Node *head1 = node1;
    Node *head2 = node2;

    // insertAtTail(3, head1);
    // insertAtTail(5, head1);
    // insertAtTail(2, head2);
    // insertAtTail(4, head2);
    // insertAtTail(5, head1);
    // insertAtTail(6, head1);
    printNodes(head1);
    printNodes(head2);
    mergeSortedLL(head1, head2);
    printNodes(head1);
}