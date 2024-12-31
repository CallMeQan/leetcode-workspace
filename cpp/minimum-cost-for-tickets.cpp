/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <algorithm>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int highest = days[days.size() - 1];
        vector<int> dp(highest+1, 0);
        dp[0] = 0;
        int cnt = 0;
        for(int i = 1; i <= highest; i++){
            if(i < days[cnt]){
                dp[i] = dp[i - 1];
                continue;
            }
            cnt++;
            int oneDay = dp[i-1] + costs[0];
            int sevenDay = dp[max((int)0, i-7)] + costs[1];
            int thirtyDay = dp[max((int)0, i-30)] + costs[2];
            dp[i] = min(oneDay, min(sevenDay, thirtyDay));
        }
        return dp[highest];
    }
};

signed main(){
    fast;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    Solution s;
    cout<<s.mincostTickets(days, costs)<<endl; //11
    days = {1,2,3,4,5,6,7,8,9,10,30,31};
    costs = {2,7,15};
    cout<<s.mincostTickets(days, costs)<<endl; //17
}
