/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

void print(vector<int> lmao)
{
    cout<<"[";
    for (auto it : lmao)
    {
        cout <<it;
        if(it != lmao[lmao.size()-1]){
            cout<<", ";
        }
    }
    cout << "]" << endl;
}
bool cmp(vector<int> a, vector<int> b){
    return a[0] <= b[0];
}

class Solution
{
public:


    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        vector<int> ans(queries.size());
        // Sort by price
        sort(items.begin(), items.end(), cmp);

        // DP to store max beauty from 0 to i
        int maxBeauty = items[0][1];
        for(int i = 1; i<items.size(); i++){
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        // Finally, easy binary search
        for(int i = 0; i<queries.size(); i++){
            ans[i] = bs(items, queries[i]);
        }
        return ans;
    }

    int bs(vector<vector<int>>& items, int target){
        int l = 0, r = items.size() - 1;
        int tmp = 0;
        while(l <= r){
            int m = l + (r-l)/2;
            if(items[m][0] > target){
                r = m - 1;
            }else{
                tmp = max(tmp, items[m][1]);
                l = m + 1;
            }
        }
        return tmp;
    }
};



signed main()
{
    fast;
    Solution s;
    vector<vector<int>> is = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> q = {1, 2, 3, 4, 5, 6};
    vector<int> res = s.maximumBeauty(is, q);
    print(res); // [2,4,5,5,6,6]

    vector<vector<int>> is2 = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    vector<int> q2 = {1};
    vector<int> res2 = s.maximumBeauty(is2, q2);
    print(res2); // [4]

    vector<vector<int>> is3 = {{10, 100}};
    vector<int> q3 = {5};
    vector<int> res3 = s.maximumBeauty(is3, q3);
    print(res3); // [0]
}
