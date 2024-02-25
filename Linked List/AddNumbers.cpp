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

Node *reverseLL(Node *head)
{
    if (!head->next)
    {
        return head;
    }
    Node *revHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return revHead;
}

Node *addLinkedLists(Node *head1, Node *head2)
{
    Node *revLL1 = reverseLL(head1);
    Node *revLL2 = reverseLL(head2);
    int sum = revLL1->data + revLL2->data;
    int carry = sum > 9 ? 1 : 0;
    Node *ans = new Node(sum % 10);
    Node *temp = ans;
    revLL1 = revLL1->next;
    revLL2 = revLL2->next;
    while (revLL1 && revLL2)
    {
        sum = revLL1->data + revLL2->data + carry;
        carry = sum > 9 ? 1 : 0;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        revLL1 = revLL1->next;
        revLL2 = revLL2->next;
    }
    while (revLL1)
    {
        sum = revLL1->data + carry;
        carry = sum > 9 ? 1 : 0;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        revLL1 = revLL1->next;
    }
    while (revLL2)
    {
        sum = revLL2->data + carry;
        carry = sum > 9 ? 1 : 0;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        revLL2 = revLL2->next;
    }
    if (carry)
    {
        Node *node = new Node(carry);
        temp->next = node;
        temp = temp->next;
    }
    return reverseLL(ans);
}

int main()
{
    Node *node1 = new Node(7);
    Node *node2 = new Node(3);

    Node *head1 = node1;
    Node *head2 = node2;

    insertAtTail(2, head1);
    insertAtTail(1, head1);
    printNodes(head1);

    insertAtTail(6, head2);
    insertAtTail(2, head2);
    printNodes(head2);

    Node *ans = addLinkedLists(head1, head2);

    printNodes(ans);
}