#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        int INF = 1e8;
        for (int i = 0; i < n; i++)
            dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= i + nums[i]; j++)
            {
                if (j < n){
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        cout<<dp[n-1]<<endl;
        if(dp[n-1] == INF) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,1,0,4};
    cout << s.canJump(nums) << endl; // true
    return 0;
}
