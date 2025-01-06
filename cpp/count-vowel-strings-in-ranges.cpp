/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
bool checker(string& str) {
    char b = str.front();
    char e = str.back();
    int tmp = 0;
    if(vowels.find(b) != vowels.end()){
        if(vowels.find(e) != vowels.end()){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int pre[words.size()];
        if(checker(words[0]))pre[0] = 1;
        else pre[0] = 0;

        for(int i = 1; i<words.size(); i++){
            if(checker(words[i])){
                pre[i] = pre[i-1] + 1;
            }else pre[i] = pre[i-1];
        }
        for(vector<int> pii: queries){
            ans.push_back(pre[pii[1]] - (pii[0] == 0 ? 0 : pre[pii[0] - 1]));
        }
        return ans;
    }
};

void printVector(const vector<int>& vec) {
    for (int x : vec) cout << x << " ";
    cout << endl;
}

signed main() {
    fast;
    Solution s;

    vector<string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> result1 = s.vowelStrings(words1, queries1);
    printVector(result1); // Output: [2, 3, 0]

    vector<string> words2 = {"a", "e", "i"};
    vector<vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};
    vector<int> result2 = s.vowelStrings(words2, queries2);
    printVector(result2); // Output: [3, 2, 1]

    return 0;
}
