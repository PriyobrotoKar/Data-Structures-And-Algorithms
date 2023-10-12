#include <iostream>
using namespace std;

class Student
{
    string name;
    int age;
    int height;

public:
    void setAge()
    {
        int n;
        cout << "enter the age of the student:";
        cin >> n;
        age = n;
    }
    int getAge()
    {
        return age;
    }
};

int main()
{
    Student ob;
    ob.setAge();
    cout << ob.getAge() << endl;
}