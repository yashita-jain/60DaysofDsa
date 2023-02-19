#include <bits/stdc++.h>
using namespace std;

int main()
{
int n=6;
int arr[n]={10,2,30,20,3,50};
vector<int>ans;
ans.push_back(arr[0]);
ans.push_back(max(ans[0],arr[1]));
for(int i=2;i<n;i++){
    ans.push_back(max((arr[i]+ans[i-2]),ans[i-1]));
}
cout<<ans[n-1]<<endl;
return 0;
}