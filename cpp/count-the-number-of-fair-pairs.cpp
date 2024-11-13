#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return 0 - lower_bound(nums, lower) + lower_bound(nums, upper + 1);
    }

    long long lower_bound(vector<int>& nums, int val){
        int l = 0, r = nums.size() - 1;
        long long res = 0;
        while (l < r){
            int tmp = nums[l] + nums[r];
            if(tmp < val){
                res += (r - l);
                l++;
            }else{
                r--;
            }
        }
        return res;
    }
};

signed main(){
    Solution s;
    vector<int> ns = {0,1,7,4,4,5};
    cout<<s.countFairPairs(ns, 3, 6)<<endl; //6
    ns = {1,7,9,2,5};
    cout<<s.countFairPairs(ns, 11, 11)<<endl; //1
}
