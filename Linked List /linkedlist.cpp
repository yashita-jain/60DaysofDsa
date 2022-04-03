#include <iostream>
#include "Node.cpp"
using namespace std;

Node *TakeInput()
{
    int data;
    cin >> data;
    Node *Head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (Head == NULL)
        {
            Head = newNode;
        }
        else
        {
            Node *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return Head;
}

Node *TakeInputBetter()
{
    int data;
    cin >> data;
    Node *Head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (Head == NULL)
        {
            Head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return Head;
}

void print(Node *Head)
{
    Node *temp = Head;
    cout << "The elements of linked list are:" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// INSERT ELEMENTS AT A POSITION
Node *insert(Node *Head, int data, int position)
{
    Node *newNode = new Node(data);
    Node *temp = Head;
    int count = 0;

    if (position == 0)
    {
        newNode->next = Head;
        Head = newNode;
        return Head;
    }
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return Head;
}

Node * insertRecursively(Node*Head,int data,int position){
Node *newNode = new Node(data);
if(position==0 && Head!=NULL){
   newNode->next=Head;
   Head=newNode;
   return Head; 
}
else {
    if(Head!=NULL){
    Node*temp=insertRecursively(Head->next,data,position-1);
    Head->next=temp;
    }
}
return Head;
}


Node *deleteNode(Node *Head, int position)
{

    int count = 0;
    Node *temp = Head;
    if (position == 0 )
    {
        Head = Head->next;
        delete temp;
        return Head;
    }

    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
    }
    return Head;
}


Node * deleteRecursively(Node*Head,int position){

if(position==0 && Head!=NULL){
   Node *a=Head;
   Head=Head->next;
   delete a;
   return Head; 
}
else {
    if(Head!=NULL){
    Node*temp=deleteRecursively(Head->next,position-1);
    Head->next=temp;
    }
}
return Head;
}


int main()
{
    // static formation of node
    //  Node n1(1);
    //  Node *Head = &n1;
    //  Node n2(2);
    //  Node n3(3);
    //  Node n4(4);
    //  Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;d

    Node *Head = TakeInputBetter();
    print(Head);
    // Head = insert(Head, 3, 0);
    // print(Head);
    // Head = deleteNode(Head, 10);
    // print(Head);
    Head = insertRecursively(Head, 4, 1);
    print(Head);
    Head = deleteRecursively(Head,0);
    print(Head);
    // Dynamic formation fo node
    //  Node *n3=new Node(3);
    //  Node *n4=new Node(4);
    //  Node *n5=new Node(5);

    // n3->next=n4;
    // n4->next=n5;

    return 0;
}