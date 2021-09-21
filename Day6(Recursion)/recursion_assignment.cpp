#include <iostream>
using namespace std;

int sum(int arr[],int size){
   if(size<=0){return 0;}
    
 int ans;
 ans=arr[size-1]+sum(arr,size-1);
 return ans;

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
   int summ= sum(a,n);
   cout<<summ<<endl;
   

return 0;
}