#include <bits/stdc++.h>
#include "../BinarySearchNode.h"
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

void PrintElementsInaRange(BinarySearchNode<int>*root,int rangeStart,int rangeEnd){
    if(root==NULL){
        return;
    }
    if(root->data>rangeEnd){
     PrintElementsInaRange(root->left,rangeStart,rangeEnd);
    }
    else if(root->data<rangeStart){
    PrintElementsInaRange(root->right,rangeStart,rangeEnd);
    }
    else{
        cout<<root->data<<" ";
        PrintElementsInaRange(root->left,rangeStart,rangeEnd);
        PrintElementsInaRange(root->right,rangeStart,rangeEnd);
    }
}

int main()
{
    BinarySearchNode<int>*root =takeInputLevelWise();
PrintElementsInaRange(root,5,12);
return 0;
}

// 10
// 8
// 11
// 5
// 9
// -1
// 12
// 4
// -1
// -1
// -1
// -1
// -1
// -1
// -1