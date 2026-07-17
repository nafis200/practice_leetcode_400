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

ListNode* reverseList(ListNode* head, ListNode* tail) {
  ListNode* prev = NULL;
  ListNode* cur = head;
  while (cur != tail) {
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

//  1 2 3 4 5

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (left == right) {
    return head;
  }
  ListNode* leftNode = head;
  ListNode* rightNode = head;

  ListNode* prev = NULL;
  ListNode* next = NULL;

  int i = 1;

  for (i; i < left; i++) {
    prev = leftNode;
    leftNode = leftNode->next;
  }

  for (i; i < right; i++) {
    rightNode = rightNode->next;
  }

  next = rightNode->next;

  ListNode* reverseHead = reverseList(leftNode, rightNode->next);

  // 1 2 3 4 5
  // 1 4 3 2 5

  if (prev != NULL) {
    prev->next = reverseHead;

  } else {
    head = reverseHead;
  }
  leftNode->next = next;
  return head;
}

int main() { return 0; }
