#include <iostream>
using namespace std;

class student{
int const rollno;
int age;
int &x; //age reference variable


student(int r,int age):rollno(r), age(age), x(this->age){

}




};