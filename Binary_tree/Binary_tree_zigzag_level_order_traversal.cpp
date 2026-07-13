

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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root == NULL){
        return ans;
    }
    int level = 0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int>v(sz);
        for(int i = 0; i < sz; i++){
            TreeNode* node = q.front();
            q.pop();
            if(level % 2 == 0){
                v[i] = node->val;
            }
            else{
                v[sz - i - 1] = node->val; 
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(v);
        level++;
    }
    return ans;
}
int32_t main(){

}