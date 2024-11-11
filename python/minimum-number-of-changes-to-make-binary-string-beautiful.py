class Solution:
    def minChanges(self, s: str) -> int:
        ans = 0
        for i in range(0, len(s), 2):
            if s[i] != s[i+1]:
                ans += 1
        return ans

if __name__ == "__main__":
    print(Solution().minChanges("1001")) # 2
    print(Solution().minChanges("10")) # 1
    print(Solution().minChanges("0000")) # 0
    print(Solution().minChanges("11000111")) # 1