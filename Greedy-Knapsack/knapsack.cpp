#include <iostream>
using namespace std;
int main()
{int n,capacity;
double weight[n],profit[n];
int i,j,m;

cout<<"Enter the no. of objects:"<<endl;
cin>>n;

// for (int i = 0; i < n; i++)

// {cout<<"Enter the weight and profit of object ";
//     cout<<i<<endl;
// cin>>weight[i]>>profit[i];    
// }

cout<<"Enter the weights of objects"<<endl;
for (int i = 0; i < n; i++)
{cin>>weight[i];
}

cout<<"Enter the profits of objects"<<endl;
for (int i = 0; i < n; i++)
{cin>>profit[i];
}

// for(int i=0;i<n;i++){
//     cout<<weight[i]<<" ";
// }



cout<<"Enter the capacity of knapsack:"<<endl;
cin>>capacity;
m=capacity;

int tp=0;

double x[n],ratio[n];
for (int i = 0; i < n; i++)
{x[i]=0;
}

for (int i = 0; i < n; i++)
{
    ratio[i]=profit[i]/weight[i];
}

for (int i = 0; i < n; i++)
{
   for (int j = i+1; j < n; j++)
   {if(ratio[j]>ratio[i]){
       swap(ratio[i],ratio[j]);
        swap(weight[i],weight[j]);
         swap(profit[i],profit[j]);
   }
   }
   }

for (int i = 0; i < n; i++)
{
    if(weight[i]>m){break;}
    else{x[i]=1;
        tp+=profit[i];
    m-=weight[i];
    }



}
if(i<n){
    x[i]=m/weight[i];

}
tp+=x[i]*profit[i];
cout<<"Total Profit is "<<tp;
return 0;
}