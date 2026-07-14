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

// temp, next = temp->next, prev = temp

//  1 2 3
//  1 1 1 2 2 3
// temp = 2, prev = 2, next = 2
 ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL){
        return head;
    }
    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->val == temp->next->val){
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


int main() {
  vector<int> nums = {1, 1, 1, 2, 3};
  ListNode* head = CreateNode(nums);
  head = deleteDuplicates(head);
  Print(head);
  return 0;
}