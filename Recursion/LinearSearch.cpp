#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int ar[5] = {2, 5, 7, 8, 6};
    int key = 4;
    cout << linearSearch(ar, 5, key) << endl;
}