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

//  1 2 3
//  1 2 2 3
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp != NULL && temp->next != NULL){
        if(temp->val == temp->next->val){
            while(temp->next && temp->val == temp->next->val){
                temp->next = temp->next->next;
            }
            if(prev != NULL){
                prev->next = temp->next;
                temp = prev->next;
            }
            else{
                head = temp->next;
                temp = head;
            }
        }
        else{
            prev = temp;
            temp = temp->next;
        }
        
    }
    return head;
 }

//   1 -> 2 --> 4

// prev = 2
int main() {
     vector<int>nums = {1,2,3,3,4,4,5};
     ListNode* head = CreateNode(nums);
     head = deleteDuplicates(head);
     Print(head);
}