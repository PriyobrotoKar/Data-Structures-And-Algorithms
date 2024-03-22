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

class Stack
{
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
    }

    bool isEmpty()
    {
        if (!top)
        {
            return true;
        }
        return false;
    }

    void push(int n)
    {
        Node *temp = new Node(n);
        if (!temp)
        {
            cout << "STACK OVERFLOW" << endl;
            return;
        }
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY" << endl;
            exit(0);
        }

        Node *temp = top;
        int data = temp->data;

        top = top->next;

        free(temp);

        return data;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY" << endl;
            exit(0);
        }

        return top->data;
    }
};

int main()
{
    Stack *s = new Stack();
    s->push(4);
    s->push(8);
    cout << s->peek() << endl;
    cout << "Popped element: " << s->pop() << endl;
    cout << s->peek() << endl;
    cout << "Popped element: " << s->pop() << endl;
    cout << s->peek() << endl;
}
