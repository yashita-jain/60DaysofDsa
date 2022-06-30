
#include <bits/stdc++.h>
using namespace std;
#include "../BinaryTreeNode.h"


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



void singleTraversal(BinaryTreeNode<int>* root,vector <int> & preorder,vector <int>& inorder,vector <int>& postorder){
if(root==NULL){
    return;
}
stack<pair<BinaryTreeNode<int>*, int> > s;
s.push({root,1});
while(s.size()!=0){
    auto it=s.top();
    s.pop();
    if(it.second==1){
        preorder.push_back(it.first->data);
        it.second++;
        s.push(it);
     if(root->left!=NULL){
         s.push({root->left,1});
     }

     }
     else if(it.second==2){
      inorder.push_back(it.first->data);
      it.second++;
        s.push(it);
    
     if(root->right!=NULL){
         s.push({root->right,1});
     }
     }
     else{
         postorder.push_back(it.first->data);
      }

}

}




int main()
{
BinaryTreeNode<int>* root= takeInputLevelWise();

vector <int> preorder;
vector <int> postorder;
vector <int> inorder;
singleTraversal(root,preorder,inorder,postorder);
for(int i=0;i<preorder.size();i++){
       cout<<preorder[i]<<" ";
   }
    cout<<endl;
    for(int i=0;i<postorder.size();i++){
       cout<<postorder[i]<<" ";
   }
    cout<<endl;
    for(int i=0;i<inorder.size();i++){
       cout<<inorder[i]<<" ";
   }
    cout<<endl;
delete root;
return 0;
}