#include <iostream>
using namespace std;
class Student {
    int rollNo;
    int age;
public:
    Student (){
        cout<<"Constructor is called"<<endl;
    }

    Student(int r){
        cout<<"Constructor 2 is called !"<<endl;
        rollNo=r;
    }

    Student(int r,int a){
        cout<<"Constructor 3 is called !"<<endl;
        rollNo=r;
        age=a;
    }
    
    ~Student (){
        cout<<"Destructor is called !"<<endl;
    }

    void display(){
         cout<<this->rollNo<<endl;
        cout<<this->age<<endl;
    }


};