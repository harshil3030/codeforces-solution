#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n));
    for (int i = 0; i < n; i++) dp[0][i] = {v[i], v[i]};
    for (int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            dp[i][j].first = dp[i-1][j].first ^ dp[i-1][j+1].first;
            dp[i][j].second = max(dp[i][j].first, max(dp[i-1][j].second, dp[i-1][j+1].second));
        }
    }   

    int q;
    cin >> q;
    while (q--) {
        int l,r;
        cin >> l >> r;
        l--, r--;
        cout << dp[r-l][l].second << "\n";
    }
}
