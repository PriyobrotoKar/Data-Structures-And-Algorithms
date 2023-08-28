#include <iostream>
using namespace std;

void update(int **p2)
{
    p2 = p2 + 1; //* This will not change anything

    *p2 = *p2 + 1; //! This will update the value of p

    **p2 = **p2 + 1; //! This wil update the value of i
}

int main()
{
    int i = 7;
    int *p = &i;
    int **p2 = &p;

    cout << "The value of i:" << endl;
    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    cout << endl;

    cout << "The value of p:" << endl;
    cout << p << endl;
    cout << &i << endl;
    cout << *p2 << endl;

    cout << endl;

    cout << "Before " << i << endl;
    cout << "Before " << p << endl;
    cout << "Before " << p2 << endl;
    update(p2);
    cout << "After " << i << endl;
    cout << "After " << p << endl;
    cout << "After " << p2 << endl;

    //? MCQs

    //* Question 1:

    int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;
    cout << first << " " << second << endl;

    //* Question 2:

    int first = 6;
    int *p = &first;
    int *q = p;
    (*q)++;
    cout << first << endl;

    //* Question 3:

    int first = 8;
    int *p = &first;
    cout << (*p)++ << " ";
    cout << first << endl;

    //* Question 4:

    int first = 8;
    int second = 11;
    int *third = &second;
    first = *third;
    *third = *third + 2;
    cout << first << " " << second << endl;

    //* Question 5:

    float f = 12.5;
    float p = 21.5;
    float *ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p << endl;

    //* Question 6:

    int arr[] = {11, 21, 13, 14};
    cout << *(arr) << ' ' << *(arr + 1) << endl;

    //* Question 7:

    int arr[6] = {11, 12, 31};
    cout << arr << " " << &arr << endl;

    //* Question 8:

    int arr[6] = {11, 12, 31};
    cout << (arr + 1) << " " << &arr[1] << endl;

    //* Question 9:

    int arr[6] = {11, 12, 31};
    int *p = arr;
    cout << p[2] << endl;

    //* Question 10:
}