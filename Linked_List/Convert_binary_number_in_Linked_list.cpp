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


int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head){
        ans = ans * 2 + head->val;
        head = head->next;
    }
    return ans;
}



int main() {
   vector<int>nums = {1, 0, 1};
   ListNode* head = CreateNode(nums);
   cout << getDecimalValue(head) << "\n";
   
}