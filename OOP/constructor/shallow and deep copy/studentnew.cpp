#include <iostream>
using namespace std;
#include <cstring>

class Student {
    int age;
    char*name;

public:
//shallow copy
// Student (int age,char*name){
// this->age=age;
// this->name=name;
// }


Student (int age,char*name){
this->age=age;
//shallow copy
// this->name=name;


//deep copy
this->name=new char[strlen(name)+1];
strcpy(this->name,name); 

}


//copy constructor
// Student(Student s){   //this will generate an infinite loop,so to avoid that passing object as reference
   
    Student(Student const &s){
    this->age=s.age;
    //shallow copy
    this->name=s.name;

    // //deep copy
    // this->name=new char[strlen(s.name)+1];
    // strcpy(this->name,s.name);
}



void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

}






};
