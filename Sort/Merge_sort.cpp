#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& nums, int low, int high) {
  if (low == high) {
    return;
  }

  int mid = (low + high) / 2;

  mergeSort(nums, low, mid);
  mergeSort(nums, mid + 1, high);

  vector<int> L, R;
  vector<int> result;
  for (int i = low; i <= mid; i++) {
    L.push_back(nums[i]);
  }

  for (int i = mid + 1; i <= high; i++) {
    R.push_back(nums[i]);
  }

  int i = 0, j = 0;
  while (i < L.size() && j < R.size()) {
    if (L[i] <= R[j]) {
      result.push_back(L[i]);
      i++;
    } else {
      result.push_back(R[j]);
      j++;
    }
  }

  while (i < L.size()) {
    result.push_back(L[i]);
    i++;
  }
  while (j < R.size()) {
    result.push_back(R[j]);
    j++;
  }
  j = 0;
  for(int i = low; i <= high; i++){
      nums[i] = result[j++];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {7, 4, 3, 1, 10};
  int n = nums.size();
  mergeSort(nums, 0, n - 1);
  for (auto i : nums) {
    cout << i << " ";
  }
}

//  0 -----> 4

//  0 -->2    3 --->4

//  0-->1  2->2    3-->4