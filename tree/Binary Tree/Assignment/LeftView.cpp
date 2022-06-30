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


void Leftview(BinaryTreeNode<int>*root){

if(root==NULL){
    return;
}
cout<<root->data<<" ";
if(root->left==NULL){
    return;
}
else{
Leftview(root->left);
}
}



void Leftviewmodified(queue <BinaryTreeNode<int>*> leftviewNodes,BinaryTreeNode<int>* root,int level){

if(root==NULL){
    return;
}

if(level==leftviewNodes.size()){
cout<<root->data<<" ";
leftviewNodes.push(root);
}
Leftviewmodified(leftviewNodes,root->left,level+1);
Leftviewmodified(leftviewNodes,root->right,level+1);

}


int main()
{
BinaryTreeNode<int>* root =takeInputLevelWise();
queue <BinaryTreeNode<int>*> leftviewNodes;
Leftviewmodified(leftviewNodes,root,0);

while (leftviewNodes.size()!=0){
cout<<leftviewNodes.front()<<endl;
leftviewNodes.pop();
}

delete root;
return 0;
}