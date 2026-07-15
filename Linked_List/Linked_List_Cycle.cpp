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

 bool hasCycle(ListNode *head) {
     if(head == NULL){
       return false;
     }
     ListNode* fast = head->next;
     ListNode* slow = head;

     while(fast!= NULL && fast->next != NULL && fast != slow){
         slow = slow->next;
         fast = fast->next->next;
     }

     if(fast == slow){
      return true;
     }
     return false;

 }


int main() {

  return 0;
}