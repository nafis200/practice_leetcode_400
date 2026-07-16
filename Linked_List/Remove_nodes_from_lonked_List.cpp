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



ListNode* removeNodes(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    head = reverse(head);
    int mx = head->val;
    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->next->val < mx){
            temp->next = temp->next->next;

        }
        else{
            mx = temp->next->val;
            temp = temp->next;
        }
    }
    head = reverse(head);
    return head;
}

int main() { 
   vector<int>nums = {5,2,13,3,8};
   ListNode* head = CreateNode(nums);
   head = removeNodes(head);
   Print(head);
} 