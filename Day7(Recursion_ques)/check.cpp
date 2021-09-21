#include <iostream>
using namespace std;

bool check(int arr[],int size,int x){
   if (size<=0){
       return false;
   }
   if(arr[1]==x){return true;}
   return check(arr+1,size-1,x); 


}
int main()
{
    int n ;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array"<<endl;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int x;
   cin>>x;
  bool summ =check(a,n,x);
  if (summ==1){ cout<<"true"<<endl;}
else{
    cout<<"false"<<endl;
}
   

return 0;
}