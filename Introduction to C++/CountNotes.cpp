#include <iostream>
using namespace std;

void countNotes(int amt)
{
    int hundNotes = 0, fifNotes = 0, twenNotes = 0, tenNotes = 0;
    hundNotes = amt / 100;
    fifNotes = (amt - hundNotes * 100) / 50;
    twenNotes = (amt - hundNotes * 100 - fifNotes * 50) / 20;
    tenNotes = (amt - hundNotes * 100 - fifNotes * 50 - twenNotes * 20) / 10;
    cout << "No. of hundred notes:" << hundNotes << endl;
    cout << "No. of fifty notes:" << fifNotes << endl;
    cout << "No. of twenty notes:" << twenNotes << endl;
    cout << "No. of ten notes:" << tenNotes << endl;
}

int main()
{
    int amount;
    cout << "Enter the amount:";
    cin >> amount;
    countNotes(amount);
}