
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

int nums;
void CountNode(TreeNode* root, int mx){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->val >= mx){
            nums++;
        }
        return;
    }
    if(root->val >= mx){
        nums++;
        mx = max(mx, root->val);
    }
    CountNode(root->left, mx);
    CountNode(root->right, mx);
    
}
int goodNodes(TreeNode* root) {
    nums = 0;
    CountNode(root, INT_MIN);
    return nums;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {3,1,4,3,-1,1,5};
  TreeNode* root = BuildTree(nums);
  cout << goodNodes(root) << "\n";
  
}