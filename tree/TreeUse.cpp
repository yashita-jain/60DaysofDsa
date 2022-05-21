#include <iostream>
// #include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void printLevelwise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *takeInput()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout << "Enter the children of " << data << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "Enter the no. of children of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the data of " << i + 1 << "children of " << front->data << endl;
            int child;
            cin >> child;
            TreeNode<int> *children = new TreeNode<int>(child);
            front->children.push_back(children);
            pendingNodes.push(children);
        }
    }
    return root;
}

TreeNode<int> *takeInputLevelWisetrial()
{
    int data;
    // cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        // cout << "Enter the no. of children of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            // cout << "Enter the data of " << i + 1 << "children of " << front->data << endl;
            int child;
            cin >> child;
            TreeNode<int> *children = new TreeNode<int>(child);
            front->children.push_back(children);
            pendingNodes.push(children);
        }
    }
    return root;
}
int NumNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += NumNodes(root->children[i]);
    }

    return ans;
}

int LargestData(TreeNode<int> *root)
{

    int largest = root->data;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {

        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front->data > largest)
        {
            largest = front->data;
        }
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << endl;
            if (front->children[i]->data > largest)
            {
                largest = front->children[i]->data;
            }
            pendingNodes.push(front->children[i]);
        }
    }
    return largest;
}

int SumNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += NumNodes(root->children[i]);
    }

    return ans;
}

int height(TreeNode<int> *root)
{

    int Height = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        Height = max(height(root->children[i]), Height);
        cout << Height << endl;
    }

    Height += 1;
    return Height;
}

void PrintTreeAtLevelK(TreeNode<int> *root, int K)
{
    if (root == NULL)
    {
        return;
    }
    if (K == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintTreeAtLevelK(root->children[i], K - 1);
    }
}

int NoOfLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int num = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        num += NoOfLeafNodes(root->children[i]);
    }

    return num;
}

void PreOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        PreOrder(root->children[i]);
    }
}

void PostOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
    }
    cout << root->data << endl;
}

int main()
{
    // TreeNode <int>* root=new TreeNode<int>(10);
    // TreeNode <int>* node1=new TreeNode<int>(20);
    // TreeNode <int>* node2=new TreeNode<int>(30);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = takeInputLevelWise();
    // printLevelwise(root);

    PostOrder(root);
    //  PrintTreeAtLevelK(root,1);

    return 0;
}
