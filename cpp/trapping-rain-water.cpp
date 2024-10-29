/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int solve(vector<int>& height){
    int n = height.size();
    int N = 1e4 + 5;
    int ans = 0;
    int b[N], c[N];

    b[0] = c[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		b[i] = max(b[i - 1], height[i-1]);
	for (int i = n; i > 0; i--)
		c[i] = max(c[i + 1], height[i-1]);
	for (int i = 1; i <= n; i++)
		ans += min(b[i], c[i]) - height[i-1];
	return ans;
}

signed main(){
    fast;
    int n;
    cin>>n;
    vector<int> kkk;
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        kkk.push_back(num);
    }

    cout<<solve(kkk);
}
