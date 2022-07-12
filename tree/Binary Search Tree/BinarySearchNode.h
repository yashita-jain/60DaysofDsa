#include <iostream>

using namespace std;

template <typename T>
class BinarySearchNode
{
public:
    T data;
    BinarySearchNode<T> *left;
    BinarySearchNode<T> *right;

    BinarySearchNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    };

    ~BinarySearchNode()
    {
        delete left;
        delete right;
    };
};

class Node{

public:

 int data;
 Node* next;

Node(int data){
this->data=data;
this->next=NULL;
 }
};