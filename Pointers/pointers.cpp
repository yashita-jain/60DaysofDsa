#include <iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void increment_pointer(int *d){
    d=d+1;

}

void increment_value_at_pointer(int *d){
    (*d)++;
}

//basically this whole array is not passed..only initial pointer is passed ,so 
//instead of arr we can use a pointer too..like this
//int sum(int* arr,int n) ; 
int sum(int arr[],int n){int sum;
    for(int i=0;i<n;i++){
        sum++;
    }
    return sum;
}

void increment1(int**ptr){
ptr=ptr+1;
}


void increment2(int**ptr){
*ptr=*ptr+1;
}


void increment3(int**ptr){
**ptr=**ptr+1;
}

int main()
{
int i=10;
cout<<i<<endl;
cout<<&i<<endl;

int *p=&i;
cout<<p<<endl;
cout<<*p<<endl;

i++;
cout<<p<<endl;
cout<<i<<endl;
cout<<&i<<endl;
cout<<*p<<endl;

(*p)++;
cout<<i<<endl;
cout<<p<<endl;

float f=10.5;
float x =2.5;
float* ptr=&f;

cout<<f<<endl;
cout<<ptr<<endl;

// *ptr=x;
// cout<<f<<endl;
// cout<<*ptr<<endl;
// cout<<x<<endl;

(*ptr)++;
*ptr=x;
cout<<f<<endl;
cout<<*ptr<<endl;
cout<<x<<endl;

int j=35;
int *k=&j;
cout<<sizeof(k)<<endl;

cout<<*k<<endl;
cout<<k<<endl;

k=k+1;
cout<<*k<<endl;
cout<<k<<endl;

int a[10];
cout<<a<<endl;
cout<<&a[0]<<endl;
a[0]=5;
cout<<*a<<endl;


//difference b/w array and operator

//sizeof
int g=30;
int *u=&g;
cout<<sizeof(a)<<endl;
cout<<sizeof(u)<<endl;

//& operator
cout<<&u<<endl;
cout<<&a<<endl;

//a once assigned can't be changed 
int *o;
o=a+1;
cout<<o<<endl;



int arr[] = {1, 2, 3, 4};
int *l= arr+1;
cout << *l << endl;


char s[]= "hello";
char *r= s;
cout << s[0]<<r[4] ;
cout<<s<<endl;
cout<<r<<endl;

char ch ='p';
char *pointer= &ch;
cout<<ch<<endl;
cout<<pointer<<endl;

// char c1 ='p';
// char *point= &c1;
// cout<<c1<<endl;
// cout<<point<<endl;


int m=10;
int *d=&m;
print(d);
cout<<d<<endl;
increment_pointer(d);
cout<<m<<endl;
increment_value_at_pointer(d);
cout<<m<<endl;


int array[10];

sum(array,10);

//the following function will enable us to acees the sum of elements 
//from index 2
//sum_desired(array+2);


int num=100;
int *nump=&num;
int **numpp=&nump;
cout<<num<<endl;
cout<<nump<<endl;
cout<<&num<<endl;
cout<<&nump<<endl;
cout<<numpp<<endl;


increment1(numpp);
cout<<num<<endl;
cout<<nump<<endl;
cout<<numpp<<endl;

increment2(numpp);
cout<<num<<endl;
cout<<nump<<endl;
cout<<numpp<<endl;

increment3(numpp);
cout<<num<<endl;
cout<<nump<<endl;
cout<<numpp<<endl;


return 0;
}





