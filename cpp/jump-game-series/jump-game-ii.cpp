/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1e9;
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
        return dp[n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums); // 2
    return 0;
}
