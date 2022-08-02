#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

int MaxFrequency(int *arr, int size)
{
   unordered_map<int, int> Map;
   for(int i=0;i<size;i++){
    if(Map.count(arr[i])==0){
    Map.insert(make_pair(arr[i],0));
  
    }else{
        Map[arr[i]]++;
       
    }

   }

 int maxn = max_element(Map.begin(), Map.end(), compare)->first;
return maxn;

}

int main()
{
    int arr[] = {1,1,2,5,3,4,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> output = DuplicateRemoval(arr, n);
    // // vector<int> &vecRef = *output;
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << endl;
    // }
    // cout << endl;
cout<<MaxFrequency(arr,n)<<endl;
    return 0;
}