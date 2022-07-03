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

int heightOfNode(BinaryTreeNode<int> *Node)
{
    if (Node == NULL)
    {
        return 0;
    }

    int lh = heightOfNode(Node->left);
    int rh = heightOfNode(Node->right);

    return 1 + max(lh, rh);
}

int DiameterOfBinaryTree(BinaryTreeNode<int> *root)
{
    int diameter = 0;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *node = pendingNodes.front();
        pendingNodes.pop();
        int CurrentDiameter = heightOfNode(node->left) + heightOfNode(node->right);
        if (diameter < CurrentDiameter)
        {
            diameter = CurrentDiameter;
        }
        if (node->left != NULL)
        {
            pendingNodes.push(node->left);
        }
        if (node->right != NULL)
        {
            pendingNodes.push(node->right);
        }
    }

    return diameter;
}

int heightPostOrder(BinaryTreeNode<int>*root,int& diameter){
 if (root == NULL)
    {
        return 0;
    }
    int lh = heightPostOrder(root->left,diameter);
    int rh = heightPostOrder(root->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1 + max(lh, rh);
}

int DiameterPostOrder(BinaryTreeNode<int>*root){
int diameter=0;
heightPostOrder(root,diameter);
return diameter;
}


int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout<<DiameterPostOrder(root);
    delete root;
    return 0;
}
