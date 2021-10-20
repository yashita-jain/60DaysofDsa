#include <iostream>
using namespace std;
#include "complexNumbers.cpp"
int main()
{
complexNumbers c1(2,3);
complexNumbers c2(3,4);
c1.print();
c2.print();

c1.add(c2);
c1.print();
c2.print();

c1.multiply(c2);
c1.print();
c2.print();

return 0;
}