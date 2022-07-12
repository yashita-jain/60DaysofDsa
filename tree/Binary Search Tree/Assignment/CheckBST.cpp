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

void maxNode(BinarySearchNode<int> *root, int &maximumNode)
{

    if (root == NULL)
    {
        return;
    }
    if (maximumNode < root->data)
    {
        maximumNode = root->data;
    }

    maxNode(root->left, maximumNode);
    maxNode(root->right, maximumNode);
}

void minNode(BinarySearchNode<int> *root, int &minimumNode)
{

    if (root == NULL)
    {
        return;
    }
    if (minimumNode > root->data)
    {
        minimumNode = root->data;
    }

    minNode(root->left, minimumNode);
    minNode(root->right, minimumNode);
}

bool checkBST(BinarySearchNode<int> *root)
{
    if (root == NULL)
    {
        return 1;
    }
    bool left = false;
    bool right = false;
    int maximumNode = INT_MIN;
    maxNode(root->left, maximumNode);
    // cout<<maximumNode<<endl;
    if (maximumNode < root->data)
    {
        left = true;
    }

    int minimumNode = INT_MAX;
    minNode(root->right, minimumNode);
    // cout<<minimumNode<<endl;
    if (minimumNode >= root->data)
    {
        right = true;
    }

    if (left==true && right==true && checkBST(root->left) && checkBST(root->right))
    {
        // cout<<"yes";
        return true;
    }

    return false;
}

int main()
{
    BinarySearchNode<int> *root = takeInputLevelWise();
   cout<< checkBST(root);
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