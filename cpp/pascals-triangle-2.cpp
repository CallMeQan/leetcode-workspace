/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> solve(int rowIndex){
    int dp[34][34];
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i<rowIndex; i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    // convert to vector and return
    vector<int> ans;
    for(int i = 0; i<rowIndex; i++){
        ans.push_back(dp[rowIndex-1][i]);
    }
    return ans;
}

signed main(){
    fast;
    int num;
    cin>>num;
    vector<int> res = solve(num);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}
