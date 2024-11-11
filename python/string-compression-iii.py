"""
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.
"""

class Solution:
    def compressedString(self, word: str) -> str:
        n = len(word)
        i = 0
        res = ""
        while i < n:
            j = i
            while j < n and word[j] == word[i] and j - i < 9:
                j += 1
            res += str(j - i) + word[i]
            i = j
        return res

if __name__ == "__main__":
    print(Solution().compressedString("abcde")) # "1a1b1c1d1e"
    print(Solution().compressedString("aaaaaaaaaaaaaabb")) # "9a5a2b
