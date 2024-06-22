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
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    int curr = 0;
    for(int len = 1; len <= n/2; len++) {
        for(int ind = 0; ind < n-len; ind++) {
            if (s[ind] == s[ind + len]) {
                if (ind == 0) {
                    dp[ind][len] = 1;
                }
                if (ind > 0)
                dp[ind][len] = dp[ind - 1][len] + 1;
            } else if (s[ind] == '?' || s[ind + len] == '?') {
                if (ind == 0) dp[ind][len] = 1;
                else dp[ind][len] = dp[ind - 1][len] + 1;
            } else {
                dp[ind][len] = 0;
            }

            if (dp[ind][len] == len) {
                curr = max(curr, 2*len);
            }
        }
    }
    cout << curr << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}