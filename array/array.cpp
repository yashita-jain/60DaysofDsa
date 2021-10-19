#include <iostream>
using namespace std;

int traversal(int arr[], int n)
{
    cout << "The elements of array are:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int insertion(int arr[], int n)
{
    int element, index;
    cout << "Enter the element you want to insert:";
    cin >> element;
    cout << "Enter the index at which you want to insert:";
    cin >> index;

    n = n + 1;
    for (int i = n; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    traversal(arr, n);
    return 0;
}

int deletion(int arr[], int n)
{
    int element, index;
    cout << "Enter the element you want to delete:";
    cin >> element;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }
    n = n - 1;
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    traversal(arr, n);

    return 0;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    traversal(arr, n);
    insertion(arr, n);
    deletion(arr, n);
    return 0;
}
