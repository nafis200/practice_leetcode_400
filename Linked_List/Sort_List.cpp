

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



//  1 2 3 4 5

//  slow = 3
//  fast = NULL
// 1 2 3

//  slow = 2
// fast = NULL

//  4 5

ListNode* Midlelist(ListNode* head){
   ListNode* temp = head;
   ListNode* fast = head->next;
   ListNode* slow = head;
   while(fast != NULL && fast->next != NULL){
       slow = slow->next;
       fast = fast->next->next;
   }
   
   ListNode* node = slow->next;
   slow->next = NULL;
   return node;
}

ListNode* mergeSort(ListNode* head, ListNode* head1){
    ListNode* a = head;
    ListNode* b = head1;
    ListNode* newhead = new ListNode(0);
    ListNode* temp = newhead;
    while(a != NULL && b != NULL){
         if(a->val < b->val){
            temp->next = a;
            a = a->next;
         }
         else{
            temp->next = b;
            b = b->next;
         }
         temp = temp->next;
    }
    while(a != NULL){
         temp->next = a;
         a = a->next;
         temp = temp->next;
    }
    while(b != NULL){
        temp->next = b;
        b = b->next;
        temp = temp->next;
    }
    return newhead->next;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }  
    ListNode* mid = Midlelist(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return mergeSort(left, right);
}


int main() { 
   vector<int>nums={4,2,1,3};
   ListNode* head = CreateNode(nums);
   head = sortList(head);
   Print(head);
} 

