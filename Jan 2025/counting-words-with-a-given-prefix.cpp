/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(string w: words){
            bool flag = true;
            for(int i = 0; i<pref.length(); i++){
                if(w[i] != pref[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    vector<string> words = {"pay","attention","practice","attend"};
    cout<<s.prefixCount(words, "at")<<endl;
    words = {"leetcode","win","loops","success"};
    cout<<s.prefixCount(words, "code")<<endl;
}
