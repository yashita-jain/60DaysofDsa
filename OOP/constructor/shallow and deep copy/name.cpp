#include <iostream>
using namespace std;
#include "studentnew.cpp"
int main()
{
char name[]="abcd";

// Student s1(20,name);
// s1.display();
// name[2]='e';
// Student s2(24,name);

// s2.display();

// s1.display();

Student s3(19,name);
s3.display();
name[2]='x';
Student s4(s3);

s4.display();
s3.display();


return 0;




}