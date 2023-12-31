#include <iostream>
#include <map>
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
}

void insertAtTailAndConnectNode(int data, Node *head, int pos)
{
    Node *node = new Node(data);
    Node *temp = head;
    Node *nodeToConnect;
    int count = 1;
    while (temp->next != NULL)
    {
        if (pos == count)
            nodeToConnect = temp;
        temp = temp->next;
        count++;
    };
    temp->next = node;
    node->next = nodeToConnect;
}

bool detectLoop1(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp)
    {
        // cout << "map " << visited[temp] << endl;
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *detectLoop2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

void startingLoopNode(Node *head)
{
    Node *temp = head;
    map<Node *, bool> visited;
    while (temp)
    {
        if (visited[temp] == true)
        {
            cout << "Starting node of the loop: " << temp->data << endl;
            return;
        }
        visited[temp] = true;
        temp = temp->next;
    }
}

Node *startingLoopNode2(Node *head)
{
    Node *intersection = detectLoop2(head);
    if (!intersection)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = intersection;

    while (true)
    {
        if (slow == fast)
        {
            return slow;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
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

int main()
{
    Node *newNode = new Node(3);
    Node *head = newNode;
    insertAtTail(5, head);
    insertAtTail(9, head);
    insertAtTail(12, head);
    insertAtTail(8, head);
    insertAtTail(32, head);
    // insertAtTailAndConnectNode(39, head, 4);
    // printNode(head);
    startingLoopNode(head);

    cout << detectLoop1(head) << endl;
    if (detectLoop2(head) != NULL)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (startingLoopNode2(head))
    {
        cout << startingLoopNode2(head)->data << endl;
    }
}