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
    vector<vector<int>> pref(n, vector<int> (27, 0));
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1];
        pref[i][v[i]]++;
    }

    int mx = 1;
    for (int ele = 1; ele <= 26; ele++) {
        int lo = 0, hi = n-1;
        int cnt = 0;
        while (lo < hi) {
            while (lo <= n-1 && v[lo] != ele) lo++;
            while (hi >= 0 && v[hi] != ele) hi--;

            if (lo >= hi) break;
            cnt++;
            int mx_freq = 0;

            for(int i = 1; i <= 26; i++) {
                mx_freq = max(mx_freq, pref[hi-1][i] - pref[lo][i]);
            }
            mx = max(mx, mx_freq + 2*cnt);
            hi--, lo++;
        }
    }
    cout << mx << "\n";






//    int mx = 1;
//    for(int i = 1; i <= 26; i++) {
//        for(int j = 1; j <= 26; j++) {
//
//            int f_ele = i, s_ele = j;
//            int l_ind = -1;
//            for(int i = n-1; i >= 0; i--) {
//                if (v[i] == f_ele) {
//                    l_ind = i;
//                    break;
//                }
//            }
//            int s_ind = n;
//            for(int i = 0; i < n-1; i++) {
//                if (v[i] == f_ele) {
//                    s_ind = i;
//                    break;
//                }
//            }
//
//            if (s_ind + 1 >= n || l_ind == -1 || l_ind == s_ind) continue;
//
//
//            vector<vector<int>> dp(n, vector<int> (3, 1));
//
//            for(int k = l_ind; k >= s_ind + 1; k--) {
//                if (k == n-1) {
//                    if (v[k] == s_ele || v[k] == f_ele) {
//                        dp[k][0]++, dp[k][1]++, dp[k][2]++;
//                    }
//                    mx = max({mx, dp[k][0], dp[k][1]});
//                    continue;
//                }
//
//                if (v[k] == s_ele) {
//                    dp[k][0] = max(dp[k+1][1] + 1, dp[k+1][0] + 1);
//                    dp[k][1] = dp[k+1][1];
//                    dp[k][2] = dp[k+1][2];
//                } else if (v[k] == f_ele) {
//                    dp[k][1] = dp[k+1][1] + 1;
//                    dp[k][2] = max(dp[k+1][2] + 1, dp[k+1][0] + 1);
//                    dp[k][0] = dp[k+1][0];
//                } else {
//                    dp[k][0] = dp[k+1][0];
//                    dp[k][1] = dp[k+1][1];
//                    dp[k][2] = dp[k+1][2];
//                }
//                mx = max({mx, dp[k][0], dp[k][1], dp[k][2]});
//            }
//        }
//    }
//    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}