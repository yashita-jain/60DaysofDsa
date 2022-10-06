#include <bits/stdc++.h>
using namespace std;

void KSortedArray(int input[],int n,int k){

  priority_queue<int>pq;
for(int i=0;i<k;i++){
    pq.push(input[i]);
}
int j=0;
for(int i=k;i<n;i++){
    input[j]=pq.top();
    pq.pop();
    pq.push(input[i]);
j++;
}

for(int i=n-k;i<n;i++){
    input[i]=pq.top();
    pq.pop();
}

}

int main()
{
int arr[]={10,12,15,6,9};
KSortedArray(arr,5,3);
for(int i=0;i<5;i++){
cout<<arr[i]<<endl;
}
return 0;
}