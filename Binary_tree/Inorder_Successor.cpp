
//       20
//      /  \
//     10   30
//    / \   / \
//   5 15 25 40

// 5 10 15 20 25 30 40

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
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  if (root == NULL) {
    return root;
  }
  TreeNode* succesor = NULL;
  if (p->right) {
    TreeNode* node = p->right;
    while (node->left != NULL) {
      node = node->left;
    }
    succesor = node;
  } else {
    TreeNode* node = root;
    while (node != NULL) {
      if (node->val > p->val) {
        succesor = node;
        node = node->left;
      } else {
        node = node->right;
      }
    }
  }
  return succesor;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3, -1, 5, -1, 4};
}