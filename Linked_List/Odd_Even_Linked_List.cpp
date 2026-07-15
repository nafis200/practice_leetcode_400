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


ListNode* addNode(ListNode* oddhead, ListNode* evenhead){
   
    ListNode* temp = oddhead;
    ListNode* temp2 = evenhead;
    while(temp2 != NULL && temp2->next != NULL){
         temp->next = temp->next->next;
         temp2->next = temp2->next->next;
         temp = temp->next;
         temp2 = temp2->next;
    }
    if(temp2){
        temp2->next == NULL;
    }
    temp->next = evenhead;
    return oddhead;
   
}


ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* temp = addNode(head, head->next);
    return temp;
}


int main() {
  vector<int> nums = {2,1,3,5,6,4,7};

  ListNode* head = CreateNode(nums);
  
  head = oddEvenList(head);
  Print(head);
  
  return 0;
}