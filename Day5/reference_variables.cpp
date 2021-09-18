#include <iostream>
using namespace std;
int increment(int n){
    n++;
    return 0;
}

int increment2(int& n){
    n++;
    return 0;
}

int increment3(int n){
    n=n+4;
    return n;
}

int main()
{
int i=20;
increment(i);
cout<<i<<endl;
increment2(i);
cout<<i<<endl;

//bad practice..value of n will have scope in function only.
//obtaining it as a reference can lead to ambiguous results(here gives error)
//int& k= increment3(i); 


//separately no memory will be assigned for j it will point towards the memory of i only.
int &j=i;




i++;
cout<<i<<endl;
j++;
cout<<j<<endl;


return 0;
}