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

Node *sortList(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zerotail = insertAtTail(0, zerohead);
        }
        else if (curr->data == 1)
        {
            onetail = insertAtTail(1, onehead);
        }
        else
        {
            twotail = insertAtTail(2, twohead);
        }
        curr = curr->next;
    }

    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }

    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main()
{
    Node *node1 = new Node(1);

    Node *head = node1;

    insertAtTail(0, head);
    insertAtTail(1, head);
    insertAtTail(2, head);
    insertAtTail(2, head);
    insertAtTail(1, head);
    insertAtTail(0, head);
    printNodes(head);
    Node *newhead = sortList(head);
    printNodes(newhead);
}