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

ListNode* middleNode(ListNode* head) {
  if (head == NULL) {
    return head;
  }
  ListNode* slow = head;
  ListNode* fast = head->next;
  while(fast != NULL && fast->next != NULL){
     slow = slow->next;
     fast = fast->next->next;
  }
  if(fast != NULL){
    slow = slow->next;
  }
  return slow;
}

int main() {
  vector<int> nums = {1, 2, 3, 5, 6};

  ListNode* head = CreateNode(nums);
  head = middleNode(head);
  Print(head);

  return 0;
}