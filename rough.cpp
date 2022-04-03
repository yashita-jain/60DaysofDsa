#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int t;
    cin>>t;
  for(int i=0;i<t;i++){
      int n;
      cin>>n;
      int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
      
      int even_index=-1,odd_index=-1;
      for(int i=0;i<n;i++){
          if(arr[i]%2==0){
              even_index=i;
              break;
          }
      }
            for(int i=0;i<n;i++){
          if(arr[i]%2!=0){
              odd_index=i;
              break;
          }
      }
      
      if(even_index==-1||odd_index==-1 ){
          cout<<"-1"<<endl;
          
      }
      else{
          int count=0;
           queue<int> q1;
             queue<int> q2;
            stack<int> s1;
             stack<int> s2;
      for(int i=0;i<n-2;i++){
          if(arr[i]%2==arr[i+1]%2){
         if(arr[i+1]%2==0){
                arr[i+1]=arr[i+1]^arr[odd_index];
                q1.push(i+1);
               q2.push(odd_index);
                // cout<<i+1<<" "<<odd_index<<endl;
                count++;
            } 
            else{arr[i+1]=arr[i+1]^arr[even_index];
              q1.push(i+1);
                q2.push(even_index);
                // cout<<i+1<<" "<<even_index<<endl;
                count++;
            }}
          } 
          int count2=0;
          for(int i=n-1;i>0;i++){
              if(arr[i]%2==arr[i-1]%2){
         if(arr[i-1]%2==0){
                arr[i-1]=arr[i-1]^arr[odd_index];
                s1.push(i-1);
               s2.push(odd_index);
                // cout<<i+1<<" "<<odd_index<<endl;
                count2++;
            } 
            else{arr[i-1]=arr[i-1]^arr[even_index];
              s1.push(i-1);
                s2.push(even_index);
                // cout<<i+1<<" "<<even_index<<endl;
                count2++;
            }}
          } 
      
      
      if(count<=count2){
          cout<<count<<endl; 
    while(!q1.empty()){
        
    cout<<q1.front()+1<<" "<<q2.front()+1<<endl;
    q1.pop();
    q2.pop();
        }
           
      }
      else{
       cout<<count<<endl; 
    while(!s1.empty()){
        
    cout<<s1.top()+1<<" "<<s2.top()+1<<endl;
    s1.pop();
    s2.pop();    
      }
      }
   
      }
      
  }  


	return 0;
}
