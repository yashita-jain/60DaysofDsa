#include <iostream>
#include "stackUsingll.cpp"
using namespace std;
int main()
{

stackUsingll <int> S;
S.push(10);
S.push(20);
S.push(30);
S.push(40);
S.push(50);
S.push(47);
S.push(60);

cout<<S.top()<<endl;
S.pop();
S.pop();
S.pop();
S.pop();
S.pop();



return 0;
}