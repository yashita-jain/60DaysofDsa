#include <bits/stdc++.h>
using namespace std;

vector<int> DuplicateRemoval(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> Map;
    for (int i = 0; i < size; i++)
    {
        if (Map.count(arr[i]) > 0)
        {
            continue;
        }
        Map[arr[i]] = true;
        output.push_back(arr[i]);
    }

    return output;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 50, 65, 34, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> output = DuplicateRemoval(arr, n);
    // vector<int> &vecRef = *output;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    cout << endl;

    return 0;
}