#include <iostream>
using namespace std;
#include "fraction.cpp"
int main()
{
Fraction f1(10,2);
Fraction f2(15,4);

Fraction f3=f1+f2;
f1.print();
f2.print();
f3.print();


if(f2==f3){
    cout<<"equal"<<endl;
}
else{cout<<"not equal"<<endl;}

Fraction f5=++f1;
f1.print();
f5.print();

// (++(++f5)).print();
Fraction f6=++(++f5);
f6.print();

f1+=f2;

Fraction f7=f6++;

return 0;
}




