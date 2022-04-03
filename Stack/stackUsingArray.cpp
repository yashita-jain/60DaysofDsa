#include <iostream>
using namespace std;

template <typename T>
class stackUsingArray{
T *data;
int nextIndex;
int capacity;

public:
stackUsingArray(){
     data=new T[4];
     nextIndex=0; 
     capacity=4;
}
bool isEmpty(){
    return nextIndex==0;
}

void push(T x){
    if(capacity==nextIndex){
    T* newData=new T[capacity*2];
    for (int i = 0; i < capacity; i++)
    {newData[i]=data[i];
    }
    capacity*=2;
    delete [] data;
    data=newData;
    }
    data[nextIndex]=x;
    nextIndex++;
}

void pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    nextIndex--;
}
int top(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    return data[nextIndex-1];
}

};

