
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

TreeNode* BuildTree(vector<int>& arr) {
  if (arr.empty()) {
    return NULL;
  }

  TreeNode* root = new TreeNode(arr[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    TreeNode* cur = q.front();
    q.pop();
    if (i < arr.size() && arr[i] != -1) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1) {
      cur->right = new TreeNode(arr[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}


int sumOfLeftLeaves(TreeNode* root) {
   if(root == NULL){
    return 0;
   }
   int sum = 0;
   if(root->left && root->left->left == NULL && root->left->right == NULL){
       sum += root->left->val;
   }

   int left = sumOfLeftLeaves(root->left);
   int right = sumOfLeftLeaves(root->right);

   return sum + left + right;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {3,9,20,-1,-1,15,7};
  TreeNode* root = BuildTree(nums);
}