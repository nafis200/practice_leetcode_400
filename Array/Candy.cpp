#include <bits/stdc++.h>
using namespace std;
// int candy(vector<int>& ratings) {
//     int n = ratings.size();
//     vector<int>candy(n, 1);
//     bool hasChanged = true;
//     while(hasChanged){
//         hasChanged = false;
//         for(int i = 0; i < n; i++){
//             if(i > 0 && ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1]){
//                 candy[i] = candy[i - 1] + 1;
//                 hasChanged = true;
//             }
//             if(i < n - 1 && ratings[i]> ratings[i + 1] && candy[i] <= candy[i + 1]){
//                 candy[i] = candy[i + 1] + 1;
//                 hasChanged = true;
//             }
//         }
//     }
//     int total_candy = 0;
//     for(auto i : candy){
//         total_candy += i;
//     }
//     return total_candy;
// }

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int>candy(n, 1);
    for(int i = 1; i < n ; i++){
        if(ratings[i] > ratings[i - 1]){
            candy[i] = candy[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(ratings[i] > ratings[i + 1]){
            candy[i] = max(candy[i],candy[i + 1] + 1);
        }
    }
    int total_candy = 0;

    for(auto i : candy){
        total_candy += i;
    }
    return total_candy;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>ratings = {3, 1, 0, 2};
  int ans = candy(ratings);
  cout << ans << "\n";
}

//  3 1 0 2

//  1 1 1 1

//  2 1 1 1
//  2 2 1 2
//  3 2 1 2
