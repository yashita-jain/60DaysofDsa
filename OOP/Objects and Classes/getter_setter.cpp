#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    int age;

public:
    void getData()
    {
        cout << "the roll number of the student is " << rollNo << endl
             << "the age of the student is " << age;
    }
    void setData(int rollNo, int age)
    { int password;
    cout<<"Enter the password: ";
    cin>>password;
    if (password==123){ 
        this->rollNo = rollNo;
        this->age = age;
    }
    else{return;}}
};

int main()
{
    Student *s1 = new Student;
    s1->setData(101, 23);
    s1->getData();
    delete s1;
    return 0;
}