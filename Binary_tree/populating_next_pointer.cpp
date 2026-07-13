
#include<bits/stdc++.h>
using namespace std;
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node(int x) {
    val = x;
    left = NULL;
    right = NULL;
    next = NULL;
  }
};

Node* BuildTree(vector<int>& arr) {
  if (arr.empty()) {
    return NULL;
  }

  Node* root = new Node(arr[0]);

  queue<Node*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    Node* cur = q.front();
    q.pop();
    if (i < arr.size() && arr[i] != -1) {
      cur->left = new Node(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1) {
      cur->right = new Node(arr[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

        //             1
        //          /     \
        //         2       3
        //       /  \     /  \
        //      4    5   6    7
        //     / \  / \ / \  / \
        //    8 9 10 1112 1314 15

  Node* connect(Node* root) {
     if(root == NULL){
        return NULL;
     }
     Node* node = root;
     while(node != NULL){
         Node* level = node;
         while(level != NULL){
             if(level->left){
                level->left->next = level->right;
             }
             if(level->right && level->next){
                level->right->next = level->next->left;
             }
             level = level->next;
         }
        node = node->left;
     }
     return root;
}       

// recursive 
// Node* connect(Node* root) {
//      if(root == NULL){
//         return NULL;
//      }
//      if(root->left != NULL){
//         root->left->next = root->right;
//      }
//      if(root->right != NULL && root->next != NULL){
//         root->right->next = root->next->left;
//      }
//    connect(root->left);
//    connect(root->right);
//    return root;
// } 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}