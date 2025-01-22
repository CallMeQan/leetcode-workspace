/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long ans = 0;
        bool bruh[n] = {0};
        vector<int> adj[n];
        for(int i = 0; i<n; i++){
            int holder = 0;
            int tmp = INT_MAX;
            for(int j = 0; j<n; j++){
                int cmp = abs(arr[i] - brr[i]);
                if(cmp < tmp){
                    holder = j;
                    tmp = cmp;
                }
            }
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;
    vector<int> arr = {-7,9,5};
    vector<int> br = {7,-2,-5};
    cout<<s.minCost(arr, br, 2)<<endl;
    arr = {2,1};
    br = {2,1};
    cout<<s.minCost(arr, br, 0)<<endl;
}
