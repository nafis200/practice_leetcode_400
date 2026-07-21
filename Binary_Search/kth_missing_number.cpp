#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
  int ans = -1;
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;

    if (arr[mid] - mid - 1 < k) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  if (ans == -1) {
    return k;
  }
  int missing = arr[ans] - ans - 1;

  missing = k - missing;

  ans = arr[ans] + missing;
  return ans;
}

int32_t main() {
  vector<int> v = {1, 2, 3, 4};
  int k = 2;
  cout << findKthPositive(v, k) << "\n";
}
//  7 - mid - 1
//  1 2 3 4 5
//  2 3 4 7 11
//

//  1 1 1 3 6

//

//  1