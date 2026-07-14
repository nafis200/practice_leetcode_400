
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


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*>mp;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    unordered_set<TreeNode*>vis;

    q.push(target);
    vis.insert(target);
    int dis = 0;
    while(!q.empty()){
       if(dis == k){
         break;
       }
      int sz = q.size();
      while(sz--){
        TreeNode* node = q.front();
        q.pop();
        if(node->left && !vis.count(node->left)){
           q.push(node->left);
           vis.insert(node->left);   
        }
        if(node->right && !vis.count(node->right)){
            q.push(node->right);
            vis.insert(node->right);
        } 
        if(mp[node] && !vis.count(mp[node])){
            q.push(mp[node]);
            vis.insert(mp[node]);
        }
      }
       
       dis++;
    }
    vector<int>ans;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};

  TreeNode* root = BuildTree(nums);
  
}