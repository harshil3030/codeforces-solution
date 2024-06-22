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
    map<int, int> big_ness;
    for(int i = 1; i < n; i++) {
        int tmp1 = v[i], tmp2 = v[i-1];
        int cnt = 0;

        if (tmp1 > tmp2) {
            while (tmp1 > tmp2) {
                tmp2*=2;
                cnt++;
            }
            if (tmp1 != tmp2) cnt--;
        } else if (tmp2 > tmp1) {
            while(tmp2 > tmp1) {
                tmp1*=2;
                cnt--;
            }
        }

        big_ness[i] = cnt;
    }

    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        dp[i] = max(0ll, dp[i-1] - big_ness[i]);
    }
    int sm  = 0;
    sm = accumulate(dp.begin(), dp.end(), 0ll);
    cout << sm << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}