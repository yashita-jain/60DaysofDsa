#include <iostream>
using namespace std;

template <typename T>
class Node{

public:
<T> data;
Node* next;

Node(T data){
this->data=data;
this->next=NULL;
 }
};


template <typename T>
class stackUsingll
{
private:
    Node <T>* head;
    int size;
public:
  
stackUsingll(/* args */)
{head=NULL;
size=0;
}

getSize(){
    return size;
}
isEmpty(){
    if(size==0){
        return true;
    }
}
void push(T element){
    Node <T> *newNode=new Node<T>(element);
    newNode->next=head;
    head=newNode;
    size++;
}

void pop(){
    if(isEmpty){
        return 0;
    }
    Node*<T> temp=head;
    head=head->next;
    delete temp;
    size--;
}

T top(){
    if(isEmpty){
        return 0;
    }
    return head->data;
}



};    
