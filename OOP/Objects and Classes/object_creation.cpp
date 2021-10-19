#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;
    int age;
};
int main()
{
    Student S1;
    Student *S2 = new Student;

    S1.rollNo = 101;
    S1.age = 23;

    (*S2).rollNo = 104;
    S2->age = 24;

    cout << S1.rollNo << endl;
    cout << S1.age << endl;
    cout << S2->rollNo << endl;
    cout << S2->age << endl;
    delete S2;
    return 0;
}