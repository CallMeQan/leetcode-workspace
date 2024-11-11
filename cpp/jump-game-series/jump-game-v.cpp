#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];
    int maxJumps(vector<int>& arr, int d) {
        for(int i = 0; i<arr.size(); i++) dp[i] = 0;
        int res=0;
        for(int i=0;i<arr.size();i++)
            res=max(res, dfs(i, d, arr));
        return res;
    }

    int dfs(int index, int d, vector<int>& arr){
        int res=1;
        if(dp[index]) return dp[index];

        for(int j=index+1; (j<=min(index+d,(int)arr.size()-1) && arr[index]>arr[j]); j++){
            res=max(res, 1+dfs(j, d, arr));
        }

        for(int j=index-1; (j>=max(index-d, 0) && arr[index]>arr[j]); j--){
            res=max(res, 1+dfs(j, d, arr));
        }

        dp[index]=res;
        return res;
    }
};

int main(){
    vector<int> nums = {6,4,14,6,8,13,9,7,10,6,12};
    Solution s;
    //cout << s.maxJumps(nums, 2) << endl; // 4
    //nums = {3,3,3,3,3};
    //cout<<s.maxJumps(nums, 3)<<endl; // 1
    nums = {7,6,5,4,3,2,1};
    cout<<s.maxJumps(nums, 1)<<endl; //7
}
