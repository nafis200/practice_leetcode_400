
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

TreeNode* Build(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(root->val > val){
        root->left = Build(root->left, val);
    }
    else{
        root->right = Build(root->right, val);
    }
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
     int n = preorder.size();
     TreeNode* root = NULL;
     for(int i = 0; i < n; i++){
        root = Build(root, preorder[i]);
     }
     return root;
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {8,5,1,7,10,12};
  TreeNode* root = BuildTree(nums);
  
}