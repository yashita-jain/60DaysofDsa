#include <iostream>
using  namespace std;
#include "../TreeNode.h"
#include <queue>
// #include "../TreeUse.cpp"

bool ContainsX(TreeNode <int>* root,int x){
if(root==NULL){
    return false;
}
if(root->data==x){
    return true;
}
int num=0;
for(int i=0;i<root->children.size();i++){
    num=ContainsX(root->children[i],x);
if(num==1){
    break;
}
}

if(num==1){
    return true;

}
return false;
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
cout<<ContainsX(root,80)<<endl;
}