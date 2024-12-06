#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int n, vector<int>& q, int target){
        int j = 0;
        int tmp = q[j];
        for(int i = 0; i<n; i++){
            if(tmp <= target){
                j++;
                if(j == q.size()){
                    return true;
                }
                else{
                    tmp = q[j];
                }
            }
            else{
                tmp -= target;
            }
        }
        return false;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = *max_element(quantities.begin(), quantities.end());
        if(n == 1) return r;

        while(l < r){
            int m = l + (r - l) / 2;
            if(check(n, quantities, m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> q = {11,6};
    cout<<s.minimizedMaximum(6, q)<<endl;
    q = {15,10,10};
    cout<<s.minimizedMaximum(7, q)<<endl;
    q = {10000};
    cout<<s.minimizedMaximum(1, q)<<endl;
}
