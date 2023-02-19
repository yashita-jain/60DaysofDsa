#include <bits/stdc++.h>
using namespace std;
int minm=INT_MAX;
// Using brute force recursion
int Staircase(int n)
{
    if (n <= 3)
    {
        return n;
    }
    int i=1,count=n;
    while(pow(i,2)<=n){
    
    count=min(count,Staircase(n-pow(i,2))+1);
    i++;            
    }
    return count;
}

//using memoization
int Staircase2_helper(int n,int *ans){
    if(n<=3){ans[n]=n;
        return ans[n];}
    
    if(ans[n]!=-1){
        return ans[n];
    }
    int i=1,count=n;
    while(pow(i,2)<=n){
    count=min(count,Staircase2_helper((n-pow(i,2)),ans)+1);
    i++;
    }
    ans[n]=count;
    return ans[n];
} 

int Staircase2(int n){

    int *ans=new int[n+1];
    for(int i=0;i<n+1;i++){ans[i]=-1;}
    ans[0]=0;

    return Staircase2_helper(n,ans);
}

//dp
int StaircaseDP(int n){
 int *ans=new int[n+1];
 ans[0]=0;
 ans[1]=1;
 ans[2]=2;
 ans[3]=3;
 for(int j=4;j<n+1;j++){
 int i=1,count=j;
    while(pow(i,2)<=j){
        int x=j-pow(i,2);
    count=min(count,ans[x]+1);
    i++;
    }
    ans[j]=count;
 }


return ans[n];
}
int main()
{
    cout << StaircaseDP(9) << endl;
    cout << StaircaseDP(12) << endl;
    cout << StaircaseDP(10) << endl;
    return 0;

}