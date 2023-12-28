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

pair<Node *, Node *> reverseLinkedListK(Node *head, int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr;
    while (curr && k != 0)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        k--;
    }
    return {forward, prev};
}

Node *reverseK(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    auto [newHead, prev] = reverseLinkedListK(head, k);
    if (newHead != NULL)
        head->next = reverseK(newHead, k);
    return prev;
}

int main()
{
    Node *newNode = new Node(3);
    Node *head = newNode;
    insertAtTail(5, head);
    insertAtTail(9, head);
    insertAtTail(12, head);
    printNode(head);
    printNode(reverseK(head, 2));
}