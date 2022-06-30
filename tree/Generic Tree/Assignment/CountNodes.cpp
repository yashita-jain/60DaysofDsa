#include <iostream>
using  namespace std;
#include "../TreeNode.h"
#include <queue>
// #include "../TreeUse.cpp"

int CountNodes(TreeNode<int>*root,int x){
    queue <TreeNode<int>*> pendingNodes;
    int count=0;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {TreeNode<int>* front=pendingNodes.front();
    if(front->data>x){
        count++;
    }
    pendingNodes.pop();
    for(int i=0;i<front->children.size();i++){
      pendingNodes.push(front->children[i]);  
    }
    }
    return count;
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

int main(){
TreeNode<int>* root=takeInputLevelWise();
printLevelwise(root);
int x;
cout<<"Enter the value of x:";
cin>>x;
cout<<CountNodes(root,x)<<endl;

}