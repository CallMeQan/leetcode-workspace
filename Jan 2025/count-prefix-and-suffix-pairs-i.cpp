/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

/*
========= EASY =========

This problem have two version, they are same but different constant.
Easy version require brute force.
Hard version require KMP optimization?
*/

class Solution {
public:
    bool isPrefixAndSuffix(string& word1, string& word2){

    }

    long long countPrefixSuffixPairs(vector<string>& words) {

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
