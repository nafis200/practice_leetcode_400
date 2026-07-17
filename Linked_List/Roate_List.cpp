

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



 ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL){
        return head;
    }
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL){
         n++;
         temp = temp->next;
    } 
    
    k = k % n;
    if(k == 0){
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 1; i <= k; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* nexthead = slow->next;
    slow->next = NULL;

    temp = nexthead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    return nexthead;
}



int main() { 
   vector<int>nums={1,2,3,4,5};
   int k = 2;
   ListNode* head = CreateNode(nums);
   head = rotateRight(head, k);
   Print(head);
} 

