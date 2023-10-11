#include <iostream>
using namespace std;

class Hero
{
public:
    string name;
    int id;

    Hero(string n, int id)
    {
        name = n;
        this->id = id;
    }

    void display()
    {
        cout << name << " " << id << endl;
    }
};

int main()
{
    Hero obj("Ramesh", 44876665);
    obj.display();
}
