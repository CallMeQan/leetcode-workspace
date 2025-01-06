/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> r(26,0);
        for(char &c : s){
            r[c - 'a']++;
            cout<<"=="<<(c-'a')<<endl;
        }
        vector<int> l(26, 0);
        unordered_set<int> sets;

        for(int i = 0; i < s.length(); i++){
            int t = s[i] - 'a';
            r[t]--;
            for(int j = 0; j < 26; j++){
                if(l[j] > 0 && r[j] > 0){
                    sets.insert(26*t + j);
                }
            }
            l[t]++;
        }

        return sets.size();
    }
};

signed main(){
    fast;
    Solution s;
    string str = "aabca";
    cout<<s.countPalindromicSubsequence(str)<<endl; // 3
    str = "adc";
    cout<<s.countPalindromicSubsequence(str)<<endl; // 0
    str = "bbcbaba";
    cout<<s.countPalindromicSubsequence(str)<<endl; // 4

}
