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


int heightOfNode(BinaryTreeNode<int> *Node,bool & balanced_binarytree)
{
    if (Node == NULL)
    {
        return 0;
    }

    int lh = heightOfNode(Node->left,balanced_binarytree);
    int rh = heightOfNode(Node->right,balanced_binarytree);

    if(lh-rh>1 || lh-rh<-1){
        balanced_binarytree= false;
    } 

    return 1 + max(lh, rh);
}



bool BalancedBinaryTree(BinaryTreeNode<int>*root){
bool balanced_binarytree=true;
heightOfNode(root,balanced_binarytree);
return balanced_binarytree;
}


int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout<<BalancedBinaryTree(root);
    delete root;
    return 0;
}
