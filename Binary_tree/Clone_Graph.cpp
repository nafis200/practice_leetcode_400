
#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node(int x) {
    val = x;
    left = NULL;
    right = NULL;
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

void preorder(Node* root) {
  if (root == NULL) return;

  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

unordered_map<Node*, Node*>mp;

Node* DFS(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(mp.find(root) != mp.end()){
        return mp[root];
    }
    Node* cloneNode = new Node(root->val);
    for(auto v : root->neighbors){
        cloneNode->push_back(DFS(v));
    }
    return cloneNode;
}

Node* cloneGraph(Node* node) {
    if(node == NULL){
        return node;
    }
    return DFS(node);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}