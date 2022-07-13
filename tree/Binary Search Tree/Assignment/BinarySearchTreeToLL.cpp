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

pair<Node *, Node *> LL(BinarySearchNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node *, Node *> p;
        return p;
    }

    pair<Node *, Node *> pL = LL(root->left);
    pair<Node *, Node *> pR = LL(root->right);

    Node *temp = new Node(root->data);

    if (pL.first == NULL && pL.second == NULL)
    {
        pair<Node *, Node *> pan = make_pair(temp, temp);
        return pan;
    }
    else
    {
        pL.second->next = temp;
        temp->next = pR.first;
    }

    pair<Node *, Node *> pans;
    pans.first = pL.first;
    pans.second = pR.second;
    return pans;
}

int main()
{
    BinarySearchNode<int> *root = takeInputLevelWise();
    pair<Node *, Node *> p = LL(root);

    while (p.first != NULL)
    {
        cout << p.first->data << endl;
        p.first = p.first->next;
    }

    return 0;
}

// 3
// 1
// 6
// 2
// -1
// 5
// 8
// -1
// -1
// -1
// -1
// -1
// -1
// -1
// -1
