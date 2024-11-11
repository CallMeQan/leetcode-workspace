class Solution:
    def makeFancyString(self, s: str) -> str:
        newStr = ""
        prev = ""
        cnt = 0
        for char in s:
            if char == prev:
                cnt += 1
            else:
                cnt = 1
                prev = char
            if cnt < 3:
                newStr += char
        return newStr

if __name__ == '__main__':
    s = "leeetcode"
    solution = Solution()
    print(solution.makeFancyString(s)) # Output: "leetcode"