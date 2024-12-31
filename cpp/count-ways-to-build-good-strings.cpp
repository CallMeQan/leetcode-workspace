/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9+7;
        long long dp[high+5];
        dp[0] = 1;
        for(int i = 1; i<=high; i++){
            long long tmp = 1;
            if (i>=zero) tmp += dp[i-zero];
            if (i>=one) tmp += dp[i-one];
            dp[i] = tmp % MOD;
        }
        return (dp[high] - dp[low-1] + MOD) % MOD;
    }
};

signed main(){
    fast;
    Solution s;
    cout<<s.countGoodStrings(3, 3, 1, 1)<<endl;// 8
    cout<<s.countGoodStrings(2, 3, 1, 2)<<endl; // 5
}
