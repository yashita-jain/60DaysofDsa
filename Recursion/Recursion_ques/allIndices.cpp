#include <iostream>
using namespace std;
int findex=0;
int check(int arr[],int size,int x){
 
   if (size<=0){
       return -1;
   }
   if(arr[0]==x){
       cout<<findex<<" ";
   }
   findex++;
   int smallOutput=check(arr+1,size-1,x)+1 ;
  return smallOutput;
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
check(a,n,x);
  
   

   

return 0;
}