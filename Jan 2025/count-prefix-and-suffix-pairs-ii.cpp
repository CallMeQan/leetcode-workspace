/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

/*
========= HARD =========

This problem have two version, they are same but different constant.
Easy version require brute force.
Hard version require KMP optimization?
*/

vector<int> prefixFunction(string s) {
    vector<int> p(s.length());
    int j = 0;
    for (int i = 1; i < s.length(); i++) {
        while (j > 0 && s[j] != s[i]){
            j = p[j-1];
        }
        if (s[j] == s[i])j++;
        p[i] = j;
    }
    return p;
}

class Solution {
public:
    bool isPrefixAndSuffix(string& word1, string& word2){

    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<int64_t, int> freq; // rolling hash => frequency
        int64_t ans = 0, mod = (int64_t)1e17 + 3;
        for (auto &w : words) {
            int64_t l_hash = 0, r_hash = 0, pow = 1;
            for (int n = w.size(), i = 1; i <= n; i++) { // i: length of prefix
                l_hash = (l_hash * 27LL + (1LL + w[i - 1] - 'a')) % mod;
                r_hash = ((1LL + w[n - i] - 'a') * pow % mod + r_hash) % mod;
                pow = pow * 27 % mod;
                if (l_hash == r_hash) {
                    auto it = freq.find(l_hash);
                    if (it != freq.end())
                        ans += it->second;
                }
            }
            ++freq[l_hash];
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    vector<string> words = {"a","aba","ababa","aa"};
    cout<<s.countPrefixSuffixPairs(words)<<endl; //4
    words = {"pa","papa","ma","mama"};
    cout<<s.countPrefixSuffixPairs(words)<<endl; //2
    words = {"abab","ab"};
    cout<<s.countPrefixSuffixPairs(words)<<endl; //0
}
