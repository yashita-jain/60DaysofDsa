#include <iostream>
using namespace std;
#include "queueUsingArray.h"
int main()
{

queueUsingArray <int> q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);
q.enqueue(50);
q.enqueue(60);

cout<<q.getSize()<<endl;
cout<<q.top()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;


return 0;
}