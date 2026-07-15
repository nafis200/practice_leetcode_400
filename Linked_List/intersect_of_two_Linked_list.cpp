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

 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if(headA == NULL || headB == NULL){
        return NULL;
    }
  
    ListNode* pa = headA;
    ListNode* pb = headB;

    while(pa != pb){
        if(pa == NULL){
            pa = headB;
        }
        else{
            pa = pa->next;
        }
        if(pb == NULL){
            pb = headA;
        }
        else{
            pb = pb->next;
        }
        
    }
    return pa;
    
}


int main() {

  return 0;
}