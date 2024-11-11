#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int p = q.front();
            q.pop();
            if(arr[p] == 0) return true;

            if(arr[p] > 0){
                int pos1 = p + arr[p];
                if(pos1 < arr.size()){
                    q.push(pos1);
                }
                int pos2 = p - arr[p];
                if(pos2 >= 0){
                    q.push(pos2);
                }
                arr[p] = -1;
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums = {3,0,2,1,2};
    Solution s;
    cout<<s.canReach(nums, 2)<<endl; // true
}
