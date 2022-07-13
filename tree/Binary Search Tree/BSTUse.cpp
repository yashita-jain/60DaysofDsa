#include <bits/stdc++.h>
#include "BST.h"
using namespace std;


// BinarySearchNode<int> *takeInputLevelWise()
// {
//     cout << "Enter the data of root" << endl;
//     int rootData;
//     cin >> rootData;
//     BinarySearchNode<int> *root = new BinarySearchNode<int>(rootData);
//     queue<BinarySearchNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     while (pendingNodes.size() != 0)
//     {
//         BinarySearchNode<int> *front = pendingNodes.front();
//         pendingNodes.pop();

//         cout << "Enter the left child of " << front->data << endl;
//         int leftChild;
//         cin >> leftChild;
//         if (leftChild != -1)
//         {
//             BinarySearchNode<int> *leftChildNode = new BinarySearchNode<int>(leftChild);
//             front->left = leftChildNode;
//             pendingNodes.push(leftChildNode);
//         }

//         cout << "Enter the right child of " << front->data << endl;
//         int rightChild;
//         cin >> rightChild;
//         if (rightChild != -1)
//         {
//             BinarySearchNode<int> *rightChildNode = new BinarySearchNode<int>(rightChild);

//             front->right = rightChildNode;
//             pendingNodes.push(rightChildNode);
//         }
//     }
//     return root;
// }

// BinarySearchNode<int>* SearchInBinaryTree(BinarySearchNode<int>* root,int value){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data==value){
//         return root;
//     }
//     else{
//         if(root->data>value){
//             return SearchInBinaryTree(root->left,value);
//         }
//         else{
//             return SearchInBinaryTree(root->right,value);
//         }
//     }
// }

int main()
{
BST b;
b.insertData(4);
b.insertData(3);
b.insertData(2);
b.insertData(5);
b.insertData(6);
b.printTree();
b.deleteData(4);
b.printTree();

return 0;
}