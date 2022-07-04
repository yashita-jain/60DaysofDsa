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

vector<vector<int>> ZigZag(BinaryTreeNode<int>*root){
    vector<vector<int>> result;
   if(root==NULL){return result;}
 queue<BinaryTreeNode<int> *> pendingNodes;
   while (pendingNodes.size() != 0){
       int size=pendingNodes.size();
       bool leftToRight=true;
       for (int i = 0; i < size; i++)
       {
           
       }
       
   }


}

vector<vector<int>> ZigZagTraversal(BinaryTreeNode<int> *root,vector<vector<int>> result)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    int level = 0;
    cout<<root->data<<" ";
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
      
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (pendingNodes.size() == 0)
        {
            level=level+1;
        }
      
          if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        if (level % 2 == 0)
        {
          if (front->left != NULL)
            {
                cout<<front->left->data<<" ";
            }
            if (front->right != NULL)
            {
                cout<<front->right->data<<" ";
            }
        }
        else
        {  if (front->right != NULL)
            {
                cout<<front->right->data<<" ";
            }
        if (front->left != NULL)
            {
                cout<<front->left->data<<" ";
            }
           
        }

        

    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    ZigZagTraversal(root);

    delete root;
    return 0;
}