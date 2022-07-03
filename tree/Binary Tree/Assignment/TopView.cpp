
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
void TopView(BinaryTreeNode<int> *root, int index)
{
    if (root == NULL)
    {
        return;
    }

    if (umap.find(index) == umap.end())
    {
        umap.insert(make_pair(index, root->data));
    }
  

    TopView(root->left, index - 1);
    TopView(root->right, index + 1);
}

void TopViewTree(BinaryTreeNode<int> *root)
{

    TopView(root, 0);
    vector<pair<int, int>> A(umap.begin(), umap.end());
    sort(A.begin(), A.end(), cmp);
    for (auto x : A)
        cout << x.first << " " << x.second << endl;
}



int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();
    TopViewTree(root);
    return 0;
}



void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({
    root,
    1
  });
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({
          it.first -> left,
          1
        });
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({
          it.first -> right,
          1
        });
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}
