#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

void solve() {
    int n, x, k;
    string s;
    cin >> n >> x >> k >> s;

    int pos = x;
    int reset_count = 0;  // Counts how many times `0` is reached
    vector<int> position(n);  // Track position at each step

    // Step 1: Simulate one full sequence
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') pos++;
        else pos--;

        position[i] = pos;  // Store position at step i

        if (pos == 0) reset_count++;  // Count how many times we hit 0
    }

    // Step 2: Determine total resets using full cycles
    int full_cycles = k / n;
    int total_resets = full_cycles * reset_count;

    // Step 3: Simulate the remaining steps (k % n)
    int remaining_steps = k % n;
    for (int i = 0; i < remaining_steps; i++) {
        if (s[i] == 'R') x++;
        else x--;

        if (x == 0) total_resets++;  // Count additional resets
    }

    cout << total_resets << endl;
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
