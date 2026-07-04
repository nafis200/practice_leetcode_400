
#include<bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    vector<int>count(30, 0);
    bool ok = true;
 
    for(int i = 0; i < (int)ransomNote.size(); i++){
        count[ransomNote[i] - 'a']++;
    }
    for(int i = 0; i < magazine.size(); i++){
        count[magazine[i]]--;
    }
    for(int i = 0; i < 30; i++){
        if(count[i] > 0){
            ok = false;
        }
    }

    return ok;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string ransomNote = "aa", magazine = "aab";
    
    bool ans = canConstruct(ransomNote, magazine);
    cout << ans << "\n";
}