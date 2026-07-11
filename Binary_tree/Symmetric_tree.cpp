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

// bool isSymmetric(TreeNode* root){
//     queue<TreeNode*>q;
//     if(root == NULL){
//         return false;
//     }
//     q.push(root->left);
//     q.push(root->right);
//     while(!q.empty()){
//         TreeNode* left = q.front();
//         q.pop();
//         TreeNode* right = q.front();
//         q.pop();
//         if(left == NULL && right == NULL){
//             continue;
//         }
//         if(left == NULL || right == NULL){
//             return false;
//         }
//         if(left->val != right->val){
//             return false;
//         }
//         q.push(left->left);
//         q.push(right->right);
//         q.push(left->right);
//         q.push(right->left);
//     }
//     return true;
// }

bool mirror(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    if(left == NULL || right == NULL){
        return false;
    }
    if(left->val != right->val){
        return false;
    }
    bool ans = true;
    ans = mirror(left->left, right->right) && mirror(left->right, right->left);
    return ans; 
}

bool isSymmetric(TreeNode* root){
    if(root == NULL){
        return false;
    }
    return mirror(root->left, root->right);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,2,2,3,4,4,3};
    TreeNode* root = BuildTree(nums);
    cout << isSymmetric(root) << "\n";
}