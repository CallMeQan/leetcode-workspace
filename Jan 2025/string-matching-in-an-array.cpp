/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    vector<int> computeLPS(const string& pat) {
        int n = pat.length();
        vector<int> lps(n, 0);
        int len = 0;

        for(int i = 1; i < n; ++i){
            while(len > 0 && pat[i] != pat[len]){
                len = lps[len -1];
            }
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }

    bool kmp_check(const string& txt, const string& pat) {
        if(pat.empty()) return true;
        if(txt.length() < pat.length()) return false;

        vector<int> lps = computeLPS(pat);
        int i = 0;
        int j = 0;

        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == pat.length()){
                    return true;
                }
            }
            else{
                if(j != 0){
                    j = lps[j -1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
            return a.length() < b.length();
        });

        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if(kmp_check(words[j], words[i])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
void printVector(const vector<string>& vec) {
    for (auto x : vec) cout << x << " ";
    cout << endl;
}

signed main(){
    fast;
    Solution s;
    vector<string> word = {"mass","as","hero","superhero"};
    printVector(s.stringMatching(word)); // ["as","hero"]
    word = {"leetcode","et","code"};
    printVector(s.stringMatching(word)); //["et","code"]
    word = {"bu", "blue", "black"};
    printVector(s.stringMatching(word)); // []
}
