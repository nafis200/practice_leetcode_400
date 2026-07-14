
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
    if (i < arr.size() && arr[i] != -1001) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1001) {
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


string serialize(TreeNode* root) {
    string s;
    if(root == NULL){
        return "";
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){

            TreeNode* node = q.front();
            q.pop();
            s += to_string(node->val) + '#';
            if(node->val == -1001){
                continue;
            }
            if(node->left){
                q.push(node->left);
            }
            else{
                q.push(new TreeNode(-1001));
            }
            if(node->right){
                q.push(node->right);
            }
            else{
                 q.push(new TreeNode(-1001));
            }
            
        }

    }
    s.pop_back();
    return s;
}



TreeNode* BuildTrees(vector<int>&arr){
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
    if (i < arr.size() && arr[i] != -1001) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1001) {
      cur->right = new TreeNode(arr[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

TreeNode* deserialize(string data) {
    if(data == ""){
        return NULL;
    }
    int n = data.size();
    int i = 0;
    vector<int>v;
    while(i < n){
        string s;
        while(i < n && data[i] != '#'){
            s += data[i];
            i++;
        }
        int x = stoi(s);
        v.push_back(x);
        i++;
    }
    
    TreeNode* root = BuildTrees(v);
    
    return root;

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {1,2,3,-1001,-1001,4,5};
  TreeNode* root = BuildTree(nums);
  
  string ans = serialize(root);
  cout << ans << "\n";
}
