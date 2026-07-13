
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

// Preorder --> root -->left --> right
// inorder --> left --> root --> right

//       3
// 9         20
//        15     7

unordered_map<int, int> mp;
int index = 0;
int n;

TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
  if (l > r) {
    return NULL;
  }
  int mid = mp[preorder[index]];
  index++;
  TreeNode* root = new TreeNode(inorder[mid]);

  root->left = Build(preorder, inorder, l, mid - 1);

  root->right = Build(preorder, inorder, mid + 1, r);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  n = preorder.size();
  for (int i = 0; i < n; i++) {
    mp[inorder[i]] = i;
  }
  return Build(preorder, inorder, 0, n - 1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}