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

Node *mergeSortedlist(Node *Head1, Node *Head2)
{
    Node *FinalHead = NULL;
    
    if (Head1->data <= Head2->data)
    {
        FinalHead = Head1;
        Head1 = Head1->next;
    }
    else
    {
        FinalHead = Head2;
        Head2 = Head2->next;
    }
    Node *FinalTail = FinalHead;
    while (Head1 != NULL && Head2 != NULL)
    {
        Node *temp = NULL;
       
        if (Head1->data <= Head2->data)
        {
            temp = Head1;
            Head1 = Head1->next;
        }
        else
        {
            temp = Head2;
            Head2 = Head2->next;
        }
        FinalTail->next = temp;
        FinalTail = temp;
    }
    if (Head1 != NULL)
    {
        FinalTail->next = Head1;
    }
    if (Head2 != NULL)
    {
        FinalTail->next = Head2;
    }

    return FinalHead;
}

Node* midPointer(Node *Head)
{
   Node* fast;
    Node* slow;
    slow = Head;
    fast = Head->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    return slow;
}

Node* sort(Node*Head){
   if(Head==NULL || Head->next==NULL){
       return Head;
   } 

 Node* mid=midPointer(Head);
 Node* middle=mid->next;
 mid->next=NULL;
 Node * Head1=sort(Head);
 Node * Head2=sort(middle);
Head=mergeSortedlist(Head1,Head2);
return Head;
}



int main()
{
    Node *Head1 = TakeInput();
    // print(Head1);
    // Node *Head2 = TakeInput();
    // print(Head2);

    // Node *Head = mergeSortedlist(Head1, Head2);
    // print(Head);

 Node *Head = sort(Head1);
    print(Head);



    return 0;
}