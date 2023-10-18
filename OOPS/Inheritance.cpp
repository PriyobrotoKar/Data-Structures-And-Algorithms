#include <iostream>
using namespace std;

class Student
{
    string name;
    int age, roll, std;

protected:
    Student(string n, int a, int r, int s)
    {
        name = n;
        age = a;
        roll = r;
        std = s;
    }
    void display()
    {
        cout << name << " " << age << " " << roll << " " << std << endl;
    }
};

class Grade : protected Student
{
    int phy, chem, maths;

public:
    Grade(string n, int a, int r, int s, int p, int c, int m) : Student(n, a, r, s)
    {
        phy = p;
        chem = c;
        maths = m;
    }
    void display()
    {
        Student::display(); //* <-- This is called Inheritance Ambiguity
        cout << "Physics marks:" << phy << " Chemistry Marks:" << chem << endl;
    }
};

int main()
{
    Grade obj("Ramesh", 13, 45, 6, 89, 77, 95);
    obj.display();
}
