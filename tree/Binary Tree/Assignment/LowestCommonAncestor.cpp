#include <bits/stdc++.h>
#include "../BinaryTreeNode.h"
using namespace std;


BinaryTreeNode<int> *takeInputLevelWise()
{
    cout << "Enter the data of root" << endl;
    int rootData;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter the left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftChildNode = new BinaryTreeNode<int>(leftChild);
            front->left = leftChildNode;
            pendingNodes.push(leftChildNode);
        }

        cout << "Enter the right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightChildNode = new BinaryTreeNode<int>(rightChild);

            front->right = rightChildNode;
            pendingNodes.push(rightChildNode);
        }
    }
    return root;
}




BinaryTreeNode<int>* LowestCommonAnestor(BinaryTreeNode<int>*  root,int val1,int val2){
   if(root==NULL|| root->data==val1|| root->data==val2){
       return root;
   }
   BinaryTreeNode<int>* left=LowestCommonAnestor(root->left,val1,val2);
   BinaryTreeNode<int>* right=LowestCommonAnestor(root->right,val1,val2);

   if(left==NULL){
       return right;
   }
  else if(right==NULL){
       return left;
   }
   else{
return root;
   }

}

int main()
{
BinaryTreeNode<int>* root =takeInputLevelWise();
cout<<LowestCommonAnestor(root,4,5)->data;

delete root;
return 0;
}