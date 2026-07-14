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

ListNode* reverseList(ListNode* head) {
   ListNode* prev = NULL;
   ListNode* temp = head;
   ListNode* next = temp;
   while(temp != NULL){
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
   }
   return prev;
}

// prev temp next

// 1  2  3 4 5

//  next = 2

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode* head = CreateNode(nums);
  head = reverseList(head);
  Print(head);
  return 0;
}