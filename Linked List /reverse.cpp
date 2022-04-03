#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Pair{
public:
Node *Head;
Node *tail;

};

Node *TakeInput()
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

Node *reverseList(Node *Head)
{
if(Head == NULL || Head->next==NULL){
return Head;
}

else{

Node*SmallAns=reverseList(Head->next);
Node *temp=SmallAns;
while(temp->next!=NULL){
    temp=temp->next;
}

temp->next=Head;
Head->next=NULL;
return SmallAns;
}
}

Pair reverseLL(Node *Head)
{
if(Head == NULL || Head->next==NULL){
Pair ans;
ans.Head=Head;
ans.tail=Head;
return ans;
}

Pair SmallAns=reverseLL(Head->next);
SmallAns.tail->next=Head;
Head->next=NULL;
Pair ans;
ans.Head=SmallAns.Head;
ans.tail=Head;
return ans;

}

Node *reverseList3(Node *Head)
{
if(Head == NULL || Head->next==NULL){
return Head;
}

else{

Node*SmallAns=reverseList(Head->next);
Node *tail=Head->next;
tail->next=Head;
Head->next=NULL;
return SmallAns;
}
}



Node *iterativeReverse(Node *Head)
{
if(Head == NULL || Head->next==NULL){
return Head;
}

Node*prev=NULL,*current=Head,*next;

while(current!=NULL){
if(next!=NULL){
prev->next=next;
current->next=next->next;
next->next=current;
}

}


}


int main()
{
    Node *Head = TakeInput();
    print(Head);
    Head =reverseList3(Head);
    print(Head);

    return 0;
}