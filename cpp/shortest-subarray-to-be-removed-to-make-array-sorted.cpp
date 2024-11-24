#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n - 1;
        while(r > 0 && arr[r] >= arr[r - 1]){
            r--;
        }
        int ans = r;
        int l = 0;
        while(l < r && (l == 0 ||arr[l - 1] <= arr[l])){

            while(r < n && arr[l] > arr[r]){
                r++;
            }
            ans = min(ans, r - l - 1);
            l++;
        }
        return ans;
    }
};

int main(){
    cout.tie(0);
    Solution s;
    vector<int> arr = {1,2,3,10,4,2,3,5}; // r = 4,
    cout<<s.findLengthOfShortestSubarray(arr)<<endl; // 3
    arr = {5,4,3,2,1};
    cout<<s.findLengthOfShortestSubarray(arr)<<endl; // 4
    arr = {1,2,3};
    cout<<s.findLengthOfShortestSubarray(arr)<<endl; // 0
}
