#include <bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
*/

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n+1];
        dp[0] = nums[0];
        deque<int> dq {0};
        for (int i = 1; i < n; i++)
        {
            int val = dq.front();
            if (val < i - k)
            {
                dq.pop_front();
                val = dq.front();
            }
            dp[i] = dp[val] + nums[i];
            while (!dq.empty() && dp[dq.back()] <= dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n-1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -1, -2, 4, -7, 3};
    int k = 2;
    cout << sol.maxResult(nums, k) << endl; // 7

    nums = {10, -5, -2, 4, 0, 3};
    k = 3;
    cout << sol.maxResult(nums, k) << endl; // 17

    nums = {1, -5, -20, 4, -1, 3, -6, -3};
    k = 2;
    cout << sol.maxResult(nums, k) << endl; // 0
    return 0;
}
