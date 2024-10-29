/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int solve(vector<int> nums){
    int n = nums.size();
    int ans = 0;
    stack<int> s;
    s.push(0);
    //cout<<"> push 0"<<endl;
    for(int i = 0; i<n; i++){
        if(nums[s.top()] > nums[i]){
            s.push(i);
    //        cout<<"> push "<<i<<endl;
        }
    }

    for(int j = n - 1; j>=0; j--){
    //    cout<<"> Start checking "<<j<<endl;
        while(!s.empty() && nums[s.top()] <= nums[j]){
    //        cout<<"nums["<<s.top()<<"] <= nums["<<j<<"]"<<endl;
    //        cout<<nums[s.top()]<<" <= "<<nums[j]<<endl;
            ans = max(ans, j - s.top());
            s.pop();
        }
    //    cout<<"> End checking "<<j<<endl;
    }
    return ans;
}

signed main(){
    fast;
    int x;
    cin>>x;
    vector<int> nums;
    for(int i = 0; i<x; i++){
        int b;
        cin>>b;
        nums.push_back(b);
    }
    cout<<solve(nums);
}
