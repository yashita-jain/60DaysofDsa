#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int pq[],int n){
    //Build the hep in input array

    for(int i=1;i<n;i++){
int childIndex=i;
while (childIndex>0)
{int parentIndex=(childIndex-1)/2;
if(pq[childIndex]<pq[parentIndex]){
    int temp=pq[childIndex];
    pq[childIndex]=pq[parentIndex];
    pq[parentIndex]=temp;
}
else{
    break;
}
childIndex=parentIndex;
}
}

//Remove elements
int size=n;
while(size>1){
int temp=pq[0];
pq[0]=pq[size-1];
pq[size-1]=temp;
size--;

  int parentIndex = 0;
        int lci = 2 * parentIndex + 1;
        int rci = 2 * parentIndex + 2;
        while (lci < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[lci])
            {
                minIndex = lci;
            }
            if (rci < size && pq[rci] < pq[minIndex])
            {
                minIndex = rci;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }

}
}

int main()
{
int input[]={5,1,2,0,8};
inplaceHeapSort(input,5);
for (int i = 0; i < 5; i++)
{cout<<input[i]<<" ";
}

return 0;
}