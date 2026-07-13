
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

unordered_map<int, vector<int>> mp;

void node(TreeNode* root, int cnt) {
  if (root == NULL) {
    return;
  }
  mp[cnt].push_back(root->val);
  node(root->left, cnt - 1);
  node(root->right, cnt + 1);
}

vector<vector<int>> vertical(TreeNode* root) {
  if (root == NULL) {
    return {{}};
  }
  node(root, 0);
  vector<vector<int>> ans;
  for (auto i : mp) {
    ans.push_back(i.second);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3, 9, 20, -1, -1, 15, 7, -1, -1, -1, -1};
  TreeNode* root = BuildTree(nums);
  vector<vector<int>>ans = vertical(root);
  for(auto v : ans){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n";
  }
}