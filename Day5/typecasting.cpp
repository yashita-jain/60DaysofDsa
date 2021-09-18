#include <iostream>
using namespace std;
int main()
{
int i=65;
char c=i;
//will convert as ASCII value
cout<<c<<endl;

int *p=&i;
char *pc=(char*)p;
cout<<*p<<endl;
cout<<*pc<<endl;
cout<<*(pc+1)<<endl;
cout<<*(pc+2)<<endl;
cout<<*(pc+3)<<endl;
cout<<p<<endl;
cout<<pc<<endl;

return 0;
}