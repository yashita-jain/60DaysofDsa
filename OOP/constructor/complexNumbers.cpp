#include <iostream>
using namespace std;
class complexNumbers{
int real;
int imaginary;

public:
complexNumbers(int real,int imaginary){
this->real=real;
this->imaginary=imaginary;
}
void print(){
    cout<<"Complex no. is: "<<real<<"+i"<<imaginary<<endl;
    }

void add(complexNumbers const &c2){
    real=real+c2.real;
    imaginary=imaginary+c2.imaginary;
   
}

void multiply(complexNumbers const &c2){
    real=(real*c2.real)-(imaginary*c2.imaginary);
    imaginary=(real*c2.imaginary)+(imaginary*c2.real);
}
};