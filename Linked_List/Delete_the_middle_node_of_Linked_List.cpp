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

ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;


    while(fast != NULL && fast->next != NULL){
         prev = slow;
         slow = slow->next;
         fast = fast->next->next;
    } 
    prev->next = slow->next;
    return head;
}



int main() {
   vector<int>nums = {1, 2, 3, 4};
   ListNode* head = CreateNode(nums);
   head = deleteMiddle(head);   
}