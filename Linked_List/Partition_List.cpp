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

ListNode* partition(ListNode* head, int x) {
    ListNode* temp = head;
    ListNode* smallHead = new ListNode(0);
    ListNode* largeHead = new ListNode(0);

    ListNode* smalltemp = smallHead;
    ListNode* largetemp = largeHead;

    while(temp != NULL){
         if(temp->val < x){
             smalltemp->next = new ListNode(temp->val);
             smalltemp = smalltemp->next;
         }
         else{
            largetemp->next = new ListNode(temp->val);
            largetemp = largetemp->next;
         }
         temp = temp->next;
    }
    smalltemp->next = largeHead->next;
    return smallHead->next;
}



int main() {
   vector<int>nums = {1,4,3,2,5,2};
   ListNode* head = CreateNode(nums);
   int x = 3;
   head = partition(head, x);
   Print(head);
   
}