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




ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL) {
    return head;
  }
  ListNode* fast = head;
  ListNode* slow = head;
  for(int i = 1; i <= n; i++){
      fast = fast->next;
  }  
  if(fast == NULL){
     head = head->next;
     return head;
  }
  while(fast != NULL && fast->next != NULL){
     slow = slow->next;
     fast = fast->next;
  }
  slow->next = slow->next->next;
  return head;
}

//  1 2 3 4 5
//      fast = 3
//  slow = 1
// slow = 2  fast = 4
// slow = 3 fast = 5

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode* head = CreateNode(nums);
  head = removeNthFromEnd(head, 1);
  Print(head);
}

//  1 2 3 4 5

// 5
// fast