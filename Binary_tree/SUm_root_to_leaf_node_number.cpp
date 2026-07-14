
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

void preorder(TreeNode* root) {
  if (root == NULL) return;

  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}


int SumOfLeavesNode(TreeNode* root, int sum){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        sum = sum * 10 + root->val;
        return sum;
    }

    int left = SumOfLeavesNode(root->left, sum * 10 + root->val);
    
    int right = SumOfLeavesNode(root->right, sum * 10 + root->val);

    return left + right;
}


int sumNumbers(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    return SumOfLeavesNode(root, 0);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 1};

  TreeNode* root = BuildTree(nums);
  cout << sumNumbers(root) << "\n";
  
}