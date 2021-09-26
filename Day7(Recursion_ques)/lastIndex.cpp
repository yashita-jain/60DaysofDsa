#include <iostream>
using namespace std;

int check(int arr[], int size, int x)
{

    if (size <= 0)
    {
        return -1;
    }
    if (arr[size - 1] == x)
    {
        return (size - 1);
    }
    int smallOutput = check(arr, size - 1, x);
    return smallOutput;
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int output = check(a, n, x);

    cout << output << endl;

    return 0;
}