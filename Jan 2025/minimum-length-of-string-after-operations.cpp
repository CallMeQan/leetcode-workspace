/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> storage(26, 0);
        for(char c : s){
            int i = c - 'a';
            storage[i]++;
            if(storage[i] > 2){
                storage[i] -= 2;
            }
        }
        return accumulate(storage.begin(), storage.end(), 0);
    }
};

signed main(){
    fast;
    Solution s;
    cout<<s.minimumLength("abaacbcbb")<<endl;//5
    cout<<s.minimumLength("aa")<<endl; //2
}
