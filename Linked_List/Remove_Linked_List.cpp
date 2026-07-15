// Google (4) — Microsoft (2) — Amazon (2)

#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;

  ListNode(int val) {
    this->val = val;
    next = NULL;
  }
};

ListNode* CreateNode(vector<int>& nums) {
  ListNode* head = NULL;
  ListNode* temp = NULL;

  for (auto x : nums) {
    ListNode* newNode = new ListNode(x);

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

void Print(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << '\n';
}

ListNode* removeElements(ListNode* head, int val) {
  if (head == NULL) {
    return NULL;
  }
  while (head != NULL && head->val == val) {
    ListNode* del = head;
    head = head->next;
    delete del;
  }
  ListNode* temp = head;
  while (temp != NULL && temp->next != NULL) {
    if (temp->next->val == val) {
      ListNode* del = temp->next;
      temp->next = temp->next->next;

      delete del;
    }
    else{
        temp = temp->next;
    }
  }
  return head;
}

int main() { return 0; }