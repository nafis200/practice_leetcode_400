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




ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* next = NULL;

    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;

}



bool isPalindrome(ListNode* head) {
   if(head == NULL || head->next == NULL){
      return true;
   }
   ListNode* mid = Midlelist(head);

   mid = reverse(mid);

   ListNode* temp = head;
   ListNode* temp1 = mid;
   while(temp != NULL && temp1 != NULL){
      if(temp->val == temp1->val){
         temp = temp->next;
         temp1 = temp1->next;
      }
      else{
        return false;
      }
   }
   return true;
}

//  2 1


int main() {
  vector<int> nums = {1, 2, 2, 1};

  ListNode* head = CreateNode(nums);
  
  ListNode* head1 = Midlelist(head);

  head1 = reverse(head1);

  Print(head1);
  

  return 0;
}