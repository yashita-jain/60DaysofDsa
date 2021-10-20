#include <iostream>
using namespace std;
#include "student.cpp"


int main()
{
//copy constructor    
Student s1(11);
s1.display();
Student s2(s1);
s2.display();

//through pointers 
Student (*S3)=new Student(15,23);
Student (*S4)=new Student(*S3);
S3->display();
S4->display();
delete S3;
delete S4;

//copy assignment operator
Student (*S5)=new Student(15,23);
Student (*S6)=new Student(20,20);
S5->display();
S6->display();
S5=S6;
S5->display();
S6->display();
delete S5;
delete S6;
return 0;
}