class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                cnt1++;
            } else {
                cnt1--;
            }
            if (cnt1 < 0) {
                return false;
            }
        }
        int cnt2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                cnt2++;
            } else {
                cnt2--;
            }
            if (cnt2 < 0) {
                return false;
            }
        }

        return true;
    }
};