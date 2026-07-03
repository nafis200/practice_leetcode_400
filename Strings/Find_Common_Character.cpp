
#include<bits/stdc++.h>
using namespace std;
vector<string> commonChars(vector<string>& words) {
    vector<string>ans;
    vector<int>mnFreq(30, INT_MAX);

    for(auto s : words){
        vector<int>freq(30, 0);
        for(auto i : s){
            int x = i - 'a';
            freq[x]++;
        }
        for(int i = 0; i < 26; i++){
             mnFreq[i] = min(mnFreq[i], freq[i]);
        }
    }
    string word = "";
    for(int i = 0; i < 26; i++){
        while(mnFreq[i] > 0){
            word = i + 'a';
            mnFreq[i]--;
            ans.push_back(word);
        }
    }

    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string>words = {"bella","label","roller"};
    vector<string>ans = commonChars(words);
    for(auto i : ans){
        cout << i << " ";
    }
}