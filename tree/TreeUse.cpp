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
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
       TreeNode<int> *front =pendingNodes.front();
       pendingNodes.pop();
       int n;
       cout<<"Enter the no. of children of "<<front->data<<endl;
       cin>>n;
       for (int i = 0; i < n; i++)
       {
           cout<<"Enter the data of "<< i +1<<"children of "<<front->data<<endl;
           int child;
           cin>>child;
           TreeNode<int> *children=new TreeNode<int>(child);
           front->children.push_back(children);
           pendingNodes.push(children); 
       }
      
    }
 return root;

}

int main()
{
    // TreeNode <int>* root=new TreeNode<int>(10);
    // TreeNode <int>* node1=new TreeNode<int>(20);
    // TreeNode <int>* node2=new TreeNode<int>(30);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = takeInputLevelWise();
    print(root);

    return 0;
}