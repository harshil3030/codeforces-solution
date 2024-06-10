#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &x : v) cin >> x;

  vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = v[0];
    dp[0][1] = abs(v[0]);
    dp[0][2] = v[0];

    for(int i = 1; i < n; i++) {
        dp[i][2] = min({v[i] + dp[i-1][0], v[i] + dp[i-1][1], v[i] + dp[i-1][2]});
        dp[i][0] = max({v[i] + dp[i-1][0], v[i] + dp[i-1][1], v[i] + dp[i-1][2]});
        dp[i][1] = max({abs(v[i] + dp[i-1][0]), abs(v[i] + dp[i-1][1]), abs(dp[i-1][2] + v[i])});
    }

    cout << max({abs(dp[n-1][0]), abs(dp[n-1][1]), abs(dp[n-1][2])}) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}