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
int ans = INT_MAX;
TreeNode* prev = NULL;
void traversal(TreeNode* root) {
  if (root == NULL) {
    return;
  }
  traversal(root->left);
  int mn = INT_MAX;
  if (prev != NULL) {
    ans = min(ans, root->val - prev->val);
  }
  prev = root;

  traversal(root->right);
}

int getMinimumDifference(TreeNode* root) {
    traversal(root);
    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}