#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

class Solution {
public:
    int bs(vector<int> primes, int target){
        int left = 0, right = primes.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (primes[mid] < target) {
            ans = primes[mid];
            left = mid + 1;
            } else {
            right = mid - 1;
            }
        }
        return ans;
    }

    bool primeSubOperation(vector<int>& nums) {
        // Sieve of Eratosthenes
        int maxNums = *max_element(nums.begin(), nums.end());

        vector<bool> prePrime(maxNums + 1, 1);
        prePrime[1] = 0;
        for (int i = 2; i <= sqrt(maxNums + 1); i++) {
            if (prePrime[i] == 1) {
                for (int j = i * i; j <= maxNums; j += i) {
                    prePrime[j] = 0;
                }
            }
        }

        int cur = 1;
        int i = 0;
        while(i < nums.size()){
            int diff = nums[i] - cur;
            if(diff < 0) return false;
            if(prePrime[diff] == true || diff == 0){
                i++;
            }
            cur++;
        }
        return true;
    }
};

signed main(){
    vector<int> nums = {4,9,6,10};
    cout<<Solution.primeSubOperation(nums)<<endl; // True
    nums = {6,8,11,12};
    cout<<Solution.primeSubOperation(nums)<<endl; // True
    nums = {5,8,3};
    cout<<Solution.primeSubOperation(nums)<<endl; // False
}
