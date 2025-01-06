/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
        int dp = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(dp>prices[i]){
                dp = prices[i];
            }
            best = max(best, prices[i] - dp);
        }
        return best;
    }
};

signed main(){
    fast;
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl; // 5
    prices = {7,6,4,3,1};
    cout<<s.maxProfit(prices)<<endl; // 0
}
