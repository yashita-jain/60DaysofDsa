#include <bits/stdc++.h>
using namespace std;

//Recursion
int BalancedBinaryTree(int h){
//Base case
if(h==1 || h==0){return 1;}

int less1=BalancedBinaryTree(h-1);
int less2=BalancedBinaryTree(h-2);
int ans=(less1*less1)+(2*(less1*less2));
return ans;
}

//Memoization
int BalancedBinaryTree2_helper(int h,int *arr){
if(h<=1){return 1;}
if(arr[h]!=-1){return arr[h];}

int less1=BalancedBinaryTree(h-1);
int less2=BalancedBinaryTree(h-2);
int ans=(less1*less1)+(2*(less1*less2));
arr[h]=ans;
return ans;
}

int BalancedBinaryTree2(int h){

int *arr=new int[h+1];
for(int i=0;i<h+1;i++){
    arr[i]=-1;
}

return BalancedBinaryTree2_helper(h,arr);

}

//DP
int BalancedBinaryTree3(int h){

int *arr=new int[h+1];
for(int i=0;i<h+1;i++){
    arr[i]=-1;
}
arr[0]=1;
arr[1]=1;
for(int i=2;i<h+1;i++){
arr[i]=(arr[i-1]*arr[i-1])+(2*(arr[i-1]*arr[i-2]));
}
return arr[h];
}

int main()
{
cout<<BalancedBinaryTree3(3);
return 0;
}