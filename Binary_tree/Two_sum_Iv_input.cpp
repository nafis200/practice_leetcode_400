
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

unordered_set<int>st;
bool findTarget(TreeNode* root, int k) {
     if(root == NULL){
        return false;
     }
     if(st.find(k - root->val) != st.end()){
        return true;
     }
     st.insert(root->val);
     bool left = findTarget(root->left, k);
     bool right = findTarget(root->right, k);
     return left || right;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}