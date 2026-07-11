
#include<bits/stdc++.h>
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

 
 bool ok;
 int depth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = depth(root->left) + 1;
    int right = depth(root->right) + 1;
    if(abs(left - right) > 1){
         ok = false;
    }
    return max(left, right);
    
 }

 bool isBalanced(TreeNode* root) {
    ok = true;  
    if(root == NULL){
        return true;
    }
    depth(root);
    return ok;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,2,2,3,3,-1,-1,4,4};
    TreeNode* root = BuildTree(nums);
    cout << isBalanced(root) << "\n";
}