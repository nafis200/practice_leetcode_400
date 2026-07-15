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

ListNode* middleNode(ListNode* head) {
  if (head == NULL) {
    return head;
  }
  ListNode* slow = head;
  ListNode* fast = head->next;
  ListNode* prev = NULL;
//   1 2 3 4
  while(fast != NULL && fast->next != NULL){
     prev = slow;
     slow = slow->next;
     fast = fast->next->next;
  }
  if(fast != NULL){
     prev = slow;
     slow = slow->next;
  }
  prev->next = NULL;
  return slow;
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

void reorderList(ListNode* head){
    if(head == NULL){
        return;
    }
    ListNode* mid = middleNode(head);
    mid = reverse(mid);
    ListNode* temp1 = head;
    ListNode* temp2 = mid;
    ListNode* temp3 = NULL;
     ListNode* temp4 = NULL;
    while(temp1 != NULL){
        temp3 = temp1->next;
        temp1->next = temp2;
        temp1 = temp3;
        temp4 = temp2->next;
        temp2->next = temp1;
        temp2 = temp4;
    }
    if(temp2 != NULL){
        temp1 = head;
        while(temp1->next != NULL){
             temp1 = temp1->next;
        } 
        temp1->next = temp2;
    }

}





int main() {
   vector<int>nums = {1, 2, 3, 4};
   ListNode* head = CreateNode(nums);
   reorderList(head);
   Print(head);
  return 0;
}