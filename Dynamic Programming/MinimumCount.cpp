#include <bits/stdc++.h>
using namespace std;

// Using brute force recursion
int Staircase(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int i=1,minm=INT_MAX;
    while((i^2)<=n){
    int count=1+Staircase((i^2)-1);
   if(count<minm){count=minm;}
    i++;            
    }
    return minm;
}

int main()
{
    cout << Staircase(9) << endl;
    // cout << Staircase(11) << endl;
    // cout << Staircase(10) << endl;
    return 0;
}