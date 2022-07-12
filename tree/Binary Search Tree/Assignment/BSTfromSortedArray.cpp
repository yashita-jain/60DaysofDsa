#include <bits/stdc++.h>
#include "../BinarySearchNode.h"
using namespace std;


void printLevelWise(BinarySearchNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinarySearchNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << front->right->data << " ";
            pendingNodes.push(front->right);
        }

        cout << endl;
    }
}



BinarySearchNode<int>* BSTfromSortedArray(int arr[],int low,int high){
if(low>high){
    return NULL;
}


   int mid =(low+high)/2;
   BinarySearchNode<int>* root=new BinarySearchNode<int>(arr[mid]);
   BinarySearchNode<int>* leftChild=BSTfromSortedArray(arr,low,mid-1);
   BinarySearchNode<int>* rightChild=BSTfromSortedArray(arr,mid+1,high);
   root->left=leftChild;
   root->right=rightChild;
   return root;



}

int main()
{
      int arr[]={1,2,3,4,5,6};
      int n=sizeof(arr)/sizeof(arr[0]);
      
    BinarySearchNode<int>*root=BSTfromSortedArray(arr,0,n-1);
printLevelWise(root);
  

return 0;
}




