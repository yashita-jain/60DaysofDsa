#include <iostream>
using namespace std;
int count=0;

int zeroes_in_num(int num){
static int number=num;
if(number==0){
    return 1;
}

if(num==0){
    return count;
}


int digit;
digit=num%10;
if(digit==0){
    count++;
}

return zeroes_in_num(num/10);

}

int main()
{
int num;
cin>>num;

int ans=zeroes_in_num(num);
cout<<ans<<endl;

return 0;
}