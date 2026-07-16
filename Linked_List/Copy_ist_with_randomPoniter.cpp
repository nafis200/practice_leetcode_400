#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int val) {
    this->val = val;
    next = NULL;
    random = NULL;
  }
};

Node* CreateNode(vector<int>& nums) {
  Node* head = NULL;
  Node* temp = NULL;

  for (auto x : nums) {
    Node* newNode = new Node(x);

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }

  return head;
}

void Print(Node* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << '\n';
}

// Node* copyRandomList(Node* head) {
//     if(head == NULL){
//         return NULL;
//     }
//     unordered_map<Node*, Node*>mp;
//     Node* cur = head;
//     while(cur != NULL){
//         mp[cur] = new Node(cur->val);
//         cur = cur->next;
//     }
//     cur = head;
//     while(cur != NULL){
//         mp[cur]->next = mp[cur->next];
//         mp[cur]->random = mp[cur->random];
//         cur = cur->next;
//     }
//     return mp[head];
// }

Node* copyRandomList(Node* head) {
  if (head == NULL) {
    return head;
  }
  Node* temp = head;
  while (temp != NULL) {
    Node* newnode = new Node(temp->val);
    Node* nextnode = temp->next;
    temp->next = newnode;
    newnode->next = nextnode;
    temp = nextnode;
  }

  temp = head;
  while (temp) {
    if (temp->random) {
      temp->next->random = temp->random->next;
    }
    temp = temp->next->next;
  }

  temp = head;
  Node* copyhead = head->next;


  while (temp) {
    Node* copy = temp->next;

    temp->next = copy->next;

    temp = temp->next;
    if(temp != NULL)
    copy->next = temp->next;
  }
  return copyhead;
}


int main() { return 0; }