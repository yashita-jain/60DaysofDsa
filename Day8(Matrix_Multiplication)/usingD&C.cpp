#include <iostream>
using namespace std;

int [][4] MMulti(int n,int A[][4],int B[][4]){
    int C[n][n];
    if(n==2){
        for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
        C[i][j]=0;
        for(int k=0;k<n;k++){
            C[i][j]+=A[i][k]*B[k][j];
        }
       
    }
   
    }}
else{
        C[1][1]=MMulti(n/2,A[1][1],B[1][1])+MMulti(n/2,A[1][2],B[2][1]);
        C[1][2]=MMulti(n/2,A[1][1],B[2][1])+MMulti(n/2,A[1][2],B[2][2]);
        C[2][1]=MMulti(n/2,A[2][1],B[1][1])+MMulti(n/2,A[2][2],B[2][1]);
        C[2][2]=MMulti(n/2,A[2][1],B[1][2])+MMulti(n/2,A[2][2],B[2][2]);
        return C;
    }
return 0;
}



int main()
{
int A[4][4]={{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
int B[4][4]={{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};

int c[4][4];


MMulti(4,A,B);



return 0;
}