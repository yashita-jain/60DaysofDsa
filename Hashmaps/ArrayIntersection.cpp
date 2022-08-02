#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

vector<int> MaxFrequency(int *a1, int n,int*a2,int m)
{vector<int> v;
   unordered_map<int, int> Map;
   for(int i=0;i<n;i++){
    if(Map.count(a1[i])==0){
    Map.insert(make_pair(a1[i],0));
  
    }else{
        Map[a1[i]]++;
       
    }}
for(int i=0;i<m;i++){
if(Map.count(a2[i])>0 && Map[a2[i]]>-1){
    v.push_back(a2[i]);
Map[a2[i]]--;
} 


   }
return v;

}

int main()
{
    int n,m;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    int a2[m];
    for(int i=0;i<m;i++){
        cin>>a2[i];
    }
   
  
   
cout<<MaxFrequency(a1,n,a2,m)<<endl;
    return 0;
}