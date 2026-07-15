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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == NULL && list2 == NULL) {
    return NULL;
  }
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }
  ListNode* temp = list1;
  ListNode* temp1 = list2;
  ListNode* head = NULL;
  ListNode* temp2 = NULL;
  while (temp != NULL && temp1 != NULL) {
    ListNode* node = NULL;
    if (temp->val <= temp1->val) {
      node = new ListNode(temp->val);
      if (head == NULL) {
        head = node;
        temp2 = node;
      } else {
        temp2->next = node;
        temp2 = temp2->next;
      }
      temp = temp->next;

    } else {
      node = new ListNode(temp1->val);
      if (head == NULL) {
        head = node;
        temp2 = node;
      } else {
        temp2->next = node;
        temp2 = temp2->next;
      }
      temp1 = temp1->next;
    }
  }
  while (temp != NULL) {
    ListNode* node = NULL;
    node = new ListNode(temp->val);
    temp2->next = node;
    temp2 = temp2->next;
    temp = temp->next;
  }
  while(temp1 != NULL){
    ListNode* node = NULL;
    node = new ListNode(temp1->val);
    temp2->next = node;
    temp2 = temp2->next;
    temp1 = temp1->next;
  }
  return head;
}

int main() {
  vector<int> list1 = {1, 2, 4};
  vector<int> list2 = {1, 3, 4};
  ListNode* listf = CreateNode(list1);
  ListNode* lists = CreateNode(list2);

  ListNode* list = mergeTwoLists(listf, lists);
  Print(list);
  return 0;
}