/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size()-1;
        long long pre[n+1];
        pre[0] = nums[0];
        for(int i = 1; i<=n; i++) pre[i] = pre[i-1] + nums[i];
        int ans = 0;
        for(int i = 0; i<=n-1; i++){
            if((pre[n] - pre[i]) <= pre[i]) ans++;
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    vector<int> nums = {10,4,-8,7};
    cout<<s.waysToSplitArray(nums)<<endl;//2
    nums = {2,3,1,0};
    cout<<s.waysToSplitArray(nums)<<endl;//2
}
