#include <iostream>
#include "Node.cpp"
using namespace std;

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

int lengthofll(Node *Head)
{
    Node *temp = Head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int midValue(int length, Node *Head)
{
    Node *slow = Head, *fast = Head->next;
    if (length % 2 != 0)
    {
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    else
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }

    return slow->data;
}

Node *mergeSortedlist(Node *Head1, Node *Head2)
{
 Node *FinalHead = NULL;
cout<<Head1->data;
    if (Head1->data <= Head2->data)
    {
        FinalHead = Head1;
        Head1=Head1->next;
    }
    else
    {
        FinalHead = Head2;
        Head2=Head2->next;
    }
    Node* FinalTail=FinalHead;
    while (Head1 != NULL && Head2 != NULL)
    {Node* temp=NULL;
        cout << "hello";
        if (Head1->data <= Head2->data)
        {temp=Head1;
            Head1 = Head1->next;
        }
        else
        {
           temp=Head2;
            Head2 = Head2->next;
        }
        FinalTail->next =temp;
            FinalTail=temp;
    }
    if (Head1 != NULL)
    {
        FinalTail->next = Head1;
           
    }
    while (Head2 != NULL)
    {
        FinalTail->next = Head2;
           
    }

    return FinalHead;
}

int main()
{

    // Node *Head = TakeInputBetter();
    // print(Head);
    // int length = lengthofll(Head);
    // cout << midValue(length, Head) << endl;

    Node *Head1 = TakeInputBetter();
    print(Head1);
    Node *Head2 = TakeInputBetter();
    print(Head2);

    Node *Head = mergeSortedlist(Head1, Head2);
    print(Head);

    return 0;
}