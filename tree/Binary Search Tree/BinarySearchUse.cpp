#include <bits/stdc++.h>
#include "BinarySearchNode.h"
using namespace std;


BinarySearchNode<int> *takeInputLevelWise()
{
    cout << "Enter the data of root" << endl;
    int rootData;
    cin >> rootData;
    BinarySearchNode<int> *root = new BinarySearchNode<int>(rootData);
    queue<BinarySearchNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter the left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinarySearchNode<int> *leftChildNode = new BinarySearchNode<int>(leftChild);
            front->left = leftChildNode;
            pendingNodes.push(leftChildNode);
        }

        cout << "Enter the right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinarySearchNode<int> *rightChildNode = new BinarySearchNode<int>(rightChild);

            front->right = rightChildNode;
            pendingNodes.push(rightChildNode);
        }
    }
    return root;
}

BinarySearchNode<int>* SearchInBinaryTree(BinarySearchNode<int>* root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->data==value){
        return root;
    }
    else{
        if(root->data>value){
            return SearchInBinaryTree(root->left,value);
        }
        else{
            return SearchInBinaryTree(root->right,value);
        }
    }
}

int main()
{
BinarySearchNode<int>* root=takeInputLevelWise();
cout<<SearchInBinaryTree(root,5)->data;
return 0;
}