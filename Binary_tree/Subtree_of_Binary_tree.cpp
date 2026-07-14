#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* BuildTree(vector<int>&arr){
     if(arr.empty()){
        return NULL;
     }

     TreeNode* root = new TreeNode(arr[0]);
   
     queue<TreeNode*>q;
     q.push(root);
     int i = 1;
     while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
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

// Time o(n * m)
// space o(n + m)

bool isSameTree(TreeNode* root, TreeNode* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }
    if(root == NULL || subRoot == NULL){
        return false;
    }
    bool left = false;
    bool right = false;
    if(root->val == subRoot->val){
       left = isSameTree(root->left, subRoot->left);
       right = isSameTree(root->right, subRoot->right);
    }

    return left && right;


}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(root == NULL){
         return false; 
      } 

     bool mid = isSameTree(root, subRoot);

     bool left = isSubtree(root->left, subRoot);
     bool right = isSubtree(root->right, subRoot);

     return mid || left || right;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {3,4,5,1,2};
    vector<int>nums1 = {4,1,2};

    TreeNode* root = BuildTree(nums);
    TreeNode* subroot = BuildTree(nums1);

}