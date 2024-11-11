#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n - 1] == '1') return false;

        queue<int> q;
        q.push(0);
        int k = 0;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(int j = max(val + minJump, k + 1); j <= min(val + maxJump, n - 1); j++){
                if(s[j] == '0'){
                    if(j == n - 1) return true;
                    q.push(j);
                }
            }
            k = min(val + maxJump, n - 1);
        }
        return false;
    }
};

int main(){
    string str = "011010";
    Solution s;
    cout<<s.canReach(str, 2, 3)<<endl; //true

    str = "01101110";
    Solution s2;
    cout<<s2.canReach(str, 2, 3)<<endl; //False

    str = "00111010";
    Solution s3;
    cout<<s3.canReach(str, 3, 5)<<endl; //false
}
