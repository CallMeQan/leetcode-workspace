class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        if (s.length() == k) return true;
        vector<int> alphabet(26);
        int cnt = 0;
        for (char& chr : s) alphabet[chr - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 1) {
                cnt++;
            }
        }
        return cnt <= k;
    }
};