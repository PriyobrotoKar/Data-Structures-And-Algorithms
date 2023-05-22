#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int divide(int a, int b)
{
    return a / b;
}
int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int x, y;
    char op;
    cout << "Enter two numbers:";
    cin >> x >> y;
    cout << "Enter the operation:";
    cin >> op;
    switch (op)
    {
    case '+':
        cout << add(x, y);
        break;
    case '-':
        cout << sub(x, y);
        break;
    case '/':
        cout << divide(x, y);
        break;
    case '*':
        cout << "The result is: " << multiply(x, y);
        break;
    }
}