
#include <bits/stdc++.h>
using namespace std;
#include "../BinaryTreeNode.h"
bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.first < b.first;
}

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


//Recursion method

unordered_map<int, int> umap;
void BottomView(BinaryTreeNode<int> *root, int index)
{
    if (root == NULL)
    {
        return;
    }

    if (umap.find(index) == umap.end())
    {
        umap.insert(make_pair(index, root->data));
    }
    else
    {
        umap[index] = root->data;
    }

    BottomView(root->left, index - 1);
    BottomView(root->right, index + 1);
}
void BottomViewTree(BinaryTreeNode<int> *root)
{

    BottomView(root, 0);
    vector<pair<int, int>> A(umap.begin(), umap.end());
    sort(A.begin(), A.end(), cmp);
    for (auto x : A)
        cout << x.first << " " << x.second << endl;
}



int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();
    BottomViewTree(root);

    return 0;
}