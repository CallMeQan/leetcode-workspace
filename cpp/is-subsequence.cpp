/*
    author: Qan
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < t.length(); j++)
            {
                if (s[i] == t[j])
                {
                    i = j;
                    cnt++;
                }
            }
        }
        return cnt == s.length();
    }
};

int main()
{
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    cout << s.isSubsequence("axc", "ahbgdc") << endl;
}
