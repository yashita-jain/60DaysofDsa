#include <iostream>
using namespace std;
int main()
{
int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int b[3][3]={{4,5,8},{3,6,2},{1,4,4}};
int c[3][3];

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        c[i][j]=0;
        for(int k=0;k<3;k++){
            c[i][j]+=a[i][k]*b[k][j];
        }
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}