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

    //     1
    //    /
    //   2
    //  / \
    // 3   4

int mx;

int DFS(TreeNode* root, int sum) {
  if (root == NULL) {
    return 0;
  }
  
  int left = DFS(root->left, sum);
  int right = DFS(root->right, sum);
  left = max(0, left);
  right = max(0, right);
  mx = max(mx, left + root->val + right);
  return root->val + max(left, right);
  
}

int maxPathSum(TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  mx = -2000;
  DFS(root, 0);
  return mx;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {-10, 9, 20, -1, -1, 15, 7};
  TreeNode* root = BuildTree(nums);
  cout << maxPathSum(root) << "\n";
}