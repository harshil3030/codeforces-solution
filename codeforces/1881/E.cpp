#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int dp[n];
    dp[n-1] = 1;

    auto get = [&](int x) -> int {
        if (x > n) return n;
        else if (x == n) return 0;
        else return dp[x];
    };
    for (int i = n-2; i >= 0; i--) {
        dp[i] = min(dp[i + 1] + 1, get(i + v[i] + 1));
    }
    cout << dp[0] << "\n";
}

