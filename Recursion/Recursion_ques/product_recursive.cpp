#include <iostream>
using namespace std;
int mindex=0;
int product(int a, int b)
{  
    if (b == 1)
    {
        return a;
    }
   
    int output = product(a, b - 1)+a;
    return output;
};

int main()
{
    int a, b;
    cin>>a>>b;
    int ans=product(a, b);
    cout<<ans<<endl;
    return 0;
}