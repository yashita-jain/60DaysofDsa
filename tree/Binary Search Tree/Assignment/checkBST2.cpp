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



class IsBSTReturn {
    public:
    int minimum;
    int maximum;
    bool IsBST;
};

IsBSTReturn checkBST2(BinarySearchNode<int>* root){
if(root==NULL){
    IsBSTReturn output;
    output.minimum=INT_MAX;
    output.maximum=INT_MIN;
    output.IsBST=true;
    return output;
}

IsBSTReturn LeftOutput=checkBST2(root->left);
IsBSTReturn RightOutput=checkBST2(root->right);

int maximum=max(root->data,max(LeftOutput.maximum,RightOutput.maximum));
int minimum=max(root->data,min(LeftOutput.minimum,RightOutput.minimum));
bool IsBSTFinal=(root->data>LeftOutput.maximum)&& (root->data<=RightOutput.minimum)&& LeftOutput.IsBST && RightOutput.IsBST;

IsBSTReturn FinalOutput;
FinalOutput.minimum=minimum;
FinalOutput.maximum=maximum;
FinalOutput.IsBST=IsBSTFinal;
return FinalOutput;
}


int main()
{
    BinarySearchNode<int> *root = takeInputLevelWise();
  cout<<checkBST2(root).IsBST;
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