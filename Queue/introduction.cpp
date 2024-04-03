#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *head, *tail;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (!tail && !head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
    }

    void pop()
    {
        Node *temp = head;
        head = head->next;
        if (!head)
        {
            tail = tail->next;
        }

        temp->next = NULL;
        free(temp);
    }

    int front()
    {
        return head->data;
    }

    int rear()
    {
        return tail->data;
    }

    bool isEmpty()
    {
        return !(head && tail);
    }
};

int main()
{
    Queue q;
    q.push(1);
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
}
