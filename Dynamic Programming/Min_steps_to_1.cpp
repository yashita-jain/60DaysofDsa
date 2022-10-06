#include <bits/stdc++.h>
using namespace std;

// Using brute force recursion
int minSteps(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    // Recursive call
    int x = minSteps(n - 1), y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minSteps(n / 2);
    }
    if (n % 3 == 0)
    {
        z = minSteps(n / 3);
    }

    // calculate final output
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

int minSteps2_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }
    // Recursive call
    int x = minSteps2_helper(n - 1,ans), y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minSteps2_helper(n / 2,ans);
    }
    if (n % 3 == 0)
    {
        z = minSteps2_helper(n / 3,ans);
    }

    // calculate final output
    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return output;
}

// Memoization
int minSteps2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    minSteps2_helper(n, ans);
    return ans[n];
}

// DP
int minSteps3(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    ans[0] = 0;
    ans[1] = 0;
    for (int i = 2; i < n+1; i++)
    {
        int x = (ans[i - 1]), y = INT_MAX, z = INT_MAX;
        if (i % 2 == 0)
        {
            y = (ans[i / 2]);
        }
        if (i % 3 == 0)
        {
            z = (ans[i / 3]);
        }
        int output=min(x,min(y,z))+1;
        ans[i]=output;
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout<<ans[i]<<endl;
    // }
    return ans[n];
}

int main()
{
    cout << minSteps3(7) << endl;
    cout << minSteps3(11) << endl;
    cout << minSteps3(10) << endl;
    return 0;
}