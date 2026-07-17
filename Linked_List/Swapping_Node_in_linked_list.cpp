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

// 1 < 2
// 1  < 4



//  5 - 2 + 1

//  5 - 1 + 1
//  5 - 3 + 3
//  5 - 4 + 1


ListNode* swapNodes(ListNode* head, int k) {
 
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    
    int cnt = n - k + 1;

    ListNode* first = head;
    ListNode* second = head;
    for(int i = 1; i < k; i++){
         first = first->next;
    }

    for(int i = 1; i < cnt; i++){
         second = second->next;
    }
    swap(first->val, second->val);
    return head;

}
 


int main() {
  vector<int>nums = {1,2,3,4,5};
  int k = 2;
  ListNode* head = CreateNode(nums);
  head = swapNodes(head, k);
  Print(head);
  return 0;
}