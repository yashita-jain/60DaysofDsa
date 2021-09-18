#include <iostream>
using namespace std;
int main()
{
  int *p=new int;//total memory used 8 bits for pointer (static) and 4 bits for int(heap)
  *p=35;
  cout<<*p<<endl;
  delete p; //this will not delete the memory used by the pointer but deallocate
           // the memory used in the heap for int.
//p pointer is in static memory it will get deleted automatically when its scope is finished  

int n;
cout<<"Enter the no. of elements"<<endl;
cin>>n;
int *j= new int[n];
cout<<"Enter the elements"<<endl;
for(int i=0;i<n;i++){
    cin>>j[i];
}
cout<<"The elements of array are ";
for(int i=0;i<n;i++){
    cout<<j[i]<<" ";
}
delete [] j;
return 0;
}