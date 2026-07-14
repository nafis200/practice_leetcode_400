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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* head = NULL;
  ListNode* temp = NULL;
  int carry = 0, val = 0;
  while (l1 != NULL && l2 != NULL) {
    val = 0;
    val = l1->val + l2->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode* node = new ListNode(val);
    if (head == NULL) {
      head = node;
      temp = node;
    } else {
      temp->next = node;
      temp = temp->next;
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != NULL) {
    int val = l1->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode* node = new ListNode(val);
    if (head == NULL) {
      head = node;
      temp = node;
    } else {
      temp->next = node;
      temp = temp->next;
    }
    l1 = l1->next;
  }

  while (l2 != NULL) {
    int val = l2->val + carry;
    carry = val / 10;
    val = val % 10;
    ListNode* node = new ListNode(val);
    if (head == NULL) {
      head = node;
      temp = node;
    } else {
      temp->next = node;
      temp = temp->next;
    }
    l2 = l2->next;
  }

  if (carry) {
    ListNode* node = new ListNode(carry);
    temp->next = node;
    temp = temp->next;
  }

  return head;
}

int main() {
  vector<int> nums = {9, 9, 9, 9, 9, 9, 9};
  vector<int> nums1 = {9, 9, 9, 9};

  ListNode* head = CreateNode(nums);
  ListNode* head1 = CreateNode(nums1);

  Print(head);
  Print(head1);

  ListNode* add = addTwoNumbers(head, head1);
  Print(add);
  return 0;
}