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
    int clz = __builtin_clzll(n);
    int fbit = 63 - clz;

    bool ok = false;
    int ans = 0;
    int ans2 = 0;
    for(int b = fbit; b >= 0; b--) {
        if (!((1ll << b) & n)) {
            ok = true;
        }
        if ((fbit - b) % 2) ans2 += (1ll << b);
        ans += (1ll << b);
    }
    if (!ok) {
        int best = 1;
        for(int i = 2; i*i <= n; i++) {
            if (n % i == 0)
                best = max(best, n/i);
        }
        cout << best << "\n";
    }else {
        cout << ans << "\n";
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}