#include <bits/stdc++.h>
using namespace std;
class Solution
{
  vector<vector<int>> ans;
  int flag = 0;

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<int> v;
    int sum = 0;
    pathSum(root, targetSum, v, sum);

    return ans;
  }

  void pathSum(TreeNode *root, int targetSum, vector<int> v, int sum)
  {
    if (root == NULL)
    {
      return;
    }
    // base case
    if (root->left == NULL && root->right == NULL)
    {
      sum += root->val;
      v.push_back(root->val);
      if (sum == targetSum)
      {
        ans.push_back(v);
        flag = 1;
      }
      return;
    }

    // small calculation
    sum += root->val;
    v.push_back(root->val);

    // recursion
    pathSum(root->left, targetSum, v, sum);
    pathSum(root->right, targetSum, v, sum);
  }
};