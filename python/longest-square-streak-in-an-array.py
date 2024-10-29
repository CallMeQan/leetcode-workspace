from typing import List

"""
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
"""
class Solution:
    def __isSquare(self, first: int, second: int) -> bool:
        return first * first == second
    
    def longestSquareStreak(self, nums: List[int]) -> int:
        ans = -1
        nums.sort()
        n = len(nums)
        dp = {}
        for num in nums:
            sqrt = int(num ** 0.5)
            if sqrt * sqrt == num and sqrt in dp:
                dp[num] = dp[sqrt] + 1
                ans = max(ans, dp[num])
            else:
                dp[num] = 1
        return ans

        
        

if __name__ == '__main__':
    s = Solution()
    nums = [4,3,6,16,8,2]
    """
    Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
    - 4 = 2 * 2.
    - 16 = 4 * 4.
    Therefore, [4,16,2] is a square streak.
    It can be shown that every subsequence of length 4 is not a square streak.
    """
    print(s.longestSquareStreak(nums)) #3


    nums = [2,3,5,6,7]
    # There is no square streak in nums so return -1.
    print(s.longestSquareStreak(nums)) #-1