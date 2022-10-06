#include <bits/stdc++.h>
using namespace std;

priority_queue<int> KSmallestArray(int input[],int n,int k)
{priority_queue <int>pq;
for(int i=0;i<k;i++){
    pq.push(input[i]);
}
for(int i=k;i<n;i++){
    if(input[i]<pq.top()){
pq.pop();
pq.push(input[i]);
}
}
return pq;

}

int main()
{
    int arr[]={23,14,56,2,7};
priority_queue pq=KSmallestArray(arr,5,3);
while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
}
return 0;
}