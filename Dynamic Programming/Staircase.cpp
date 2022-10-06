#include <bits/stdc++.h>
using namespace std;

// Using brute force recursion
int Staircase(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if(n<0){

        return 0;
    }

    // Recursive call
    int x = Staircase(n - 1);
    int y = Staircase(n - 2);
    int z = Staircase(n - 3);
    return x+y+z;
}

int Staircase2_helper(int n,int*ans){
     if (n == 0)
    {
        return 1;
    }
    if(n<0){
        return 0;
    }
    
    if(ans[n]!=-1){
        return ans[n];
    }
    // Recursive call
    int x = Staircase2_helper(n - 1,ans);
    int y = Staircase2_helper(n - 2,ans);
    int z = Staircase2_helper(n - 3,ans);
    int output=x+y+z;
    ans[n]=output;
    return output;
}

//Memoization
int Staircase2(int n){
    int*ans=new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    ans[0]=0;
    Staircase2_helper(n,ans);
    return ans[n];
}

//DP
int Staircase3(int n){
 int*ans=new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<n+1;i++){
        int output=ans[i-1]+ans[i-2]+ans[i-3];
        ans[i]=output;
    }
    return ans[n];
}

int main()
{
    cout << Staircase3(4) << endl;
    // cout << Staircase(11) << endl;
    // cout << Staircase(10) << endl;
    return 0;
}