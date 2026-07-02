
#include<bits/stdc++.h>
using namespace std;
int hIndex(vector<int>& citations) {
    sort(citations.rbegin(),citations.rend());
    
    int ans = 0;
    for(int i = 0; i < citations.size(); i++){
        if(i + 1 <= citations[i]){
            ans = i + 1;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//  3 0 6 1 5

// 6 5 3 0 1

// 1 2 3 4 