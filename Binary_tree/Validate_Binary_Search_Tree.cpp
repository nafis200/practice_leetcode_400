
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

    //     10
    //    /  \
    //   5   15   10   inifnity
    //      /  \
    //     13   20
    //  10  13  15    15   infiity

// -infinty   +infinty

//  -infinty    10

// 10   15    infinity

// 10     15      15        infity

bool isValid(TreeNode* root, long long mn, long long mx) {
    if(root == NULL){
        return true;
    }
    if(root->val <= mn || root->val >= mx){
        return false;
    }

    bool left = isValid(root->left, mn, root->val);

    bool right = isValid(root->right, root->val, mx);

    return left && right;
}

bool isValidBST(TreeNode* root) {
   return isValid(root, LLONG_MIN, LLONG_MAX);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}