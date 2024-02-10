#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;

void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[j] <= i) {
                dp[i] = max(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
}
