// Write a program to print the names of students by creating a Student class. If no name is passed while creating an object of the Student class, then the name should be "Unknown", otherwise the name should be equal to the String value passed while creating the object of the Student class.

#include <iostream>
using namespace std;
class Student{
char *name;
public:
Student(){
    this->name='Unknown';
    }

Student(char *name){
    this->name=name;
}    

void display(){
    cout<<"The name of the student is "<<name<<endl;
}

};
int main()
{
//    Student s1;
//    s1.display();
   char name[]="shelly"; 
   Student s2(name);
   s2.display();
return 0;
}