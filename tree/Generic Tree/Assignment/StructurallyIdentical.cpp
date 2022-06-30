#include <iostream>
using namespace std;
#include "../TreeNode.h"
#include <queue>
// #include "../TreeUse.cpp"

bool StructurallyIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    queue<TreeNode<int> *> pendingNodes1;
    queue<TreeNode<int> *> pendingNodes2;
    pendingNodes1.push(root1);
    pendingNodes2.push(root2);
    while (pendingNodes1.size() != 0)
    {
        TreeNode<int> *front1 = pendingNodes1.front();
        TreeNode<int> *front2 = pendingNodes2.front();
        pendingNodes1.pop();
        pendingNodes2.pop();
        if (front1->data != front2->data)
        {
            return false;
        }
        if (front1->children.size() != front2->children.size())
        {
            return false;
        }
        for (int i = 0; i < front1->children.size(); i++)
        {
            if (front1->children[i]->data != front2->children[i]->data)
            {
                return false;
            }
            pendingNodes1.push(front1->children[i]);
            pendingNodes2.push(front2->children[i]);
        }
    }
    return true;
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

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    printLevelwise(root1);
    TreeNode<int> *root2 = takeInputLevelWise();
    printLevelwise(root2);
    cout << StructurallyIdentical(root1, root2) << endl;
}