/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        int ans = 0;
        int cnt2 = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == '1')cnt--;
            else{
                cnt2++;
            }
            ans = max(ans, cnt2+cnt);
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    string str = "011101";
    cout<<s.maxScore(str)<<endl; //5
    str = "00111";
    cout<<s.maxScore(str)<<endl; //5
    str = "1111";
    cout<<s.maxScore(str)<<endl;//3
    str = "00";
    cout<<s.maxScore(str)<<endl;//1
}
