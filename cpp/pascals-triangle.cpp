/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<vector<int>> solve(int numRows){
    vector<vector<int>> ans;
    vector<int> f1, f2;
    //0
    f1.push_back(1);
    //1
    f2.push_back(1);
    f2.push_back(1);
    // push f1 and f2 first
    if(numRows == 0) return ans;
    ans.push_back(f1);
    if(numRows == 1) return ans;
    ans.push_back(f2);
    if(numRows == 2) return ans;

    for(int i = 2; i<numRows; i++){
        vector<int> prev = ans[i-1];
        vector<int> tmp;
        tmp.push_back(1);
        for(int j = 1; j<i; j++){
            tmp.push_back(prev[j-1] + prev[j]);
        }
        tmp.push_back(1);
        ans.push_back(tmp);
    }
    return ans;
}

signed main(){
    fast;
    int num;
    cin>>num;
    vector<vector<int>> res = solve(num);
    for(int i = 0; i<res.size(); i++){
        cout<<"[";
        for(int j = 0; j<res[i].size(); j++){
            cout<<res[i][j]<<",";
        }
        cout<<"]";
    }
}
