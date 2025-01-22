/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums[nums.size() - 1]);
        for(int i = 1; i<nums.size(); i++){
            ans = max(ans, abs(nums[i] - nums[i-1]));
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    vector<int> nu = {-5,-10,-5};
    cout<<s.maxAdjacentDistance(nu)<<endl;
    nu = {1,2,4};
    cout<<s.maxAdjacentDistance(nu)<<endl;
}
