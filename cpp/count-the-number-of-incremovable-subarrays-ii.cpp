// For version 1 and 2

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), pre = 0, suff = n - 1;
        long ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1])
                pre = i;
            else
                break;
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] < nums[i + 1])
                suff = i;
            else
                break;
        }
        ans += (n - suff) + ((suff > 0) ? 1 : 0);
        for(int i = 1 ; i <= pre + 1 ; i++){
            while(suff < n && nums[suff] <= nums[i - 1])
                suff++;
            ans += (n - suff) + ((suff - i > 0) ? 1 : 0);
        }
        return ans;
    }
};
