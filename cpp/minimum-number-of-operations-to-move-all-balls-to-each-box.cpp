/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);
        for(int i = 0; i<n; i++){ // hold
            int cnt = 1;
            for(int j = i + 1; j< n; j++){ // Right array
                if(boxes[j] == '1') ans[i] += cnt;
                cnt++;
            }
            cnt = 1;
            for(int j = i - 1; j>=0; j--){ // Left array
                if(boxes[j] == '1'){
                    ans[i] += cnt;
                }
                cnt++;
            }
        }
        return ans;
    }
};

void printVector(const vector<int>& vec) {
    for (int x : vec) cout << x << " ";
    cout << endl;
}

signed main(){
    fast;
    Solution s;
    string boxes = "110";
    printVector(s.minOperations(boxes)); // [1,1,3]
    boxes = "001011";
    printVector(s.minOperations(boxes)); // [11,8,5,4,3,4]
}
