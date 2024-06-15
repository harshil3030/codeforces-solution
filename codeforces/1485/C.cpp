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
    int n,m;
    cin >> n >> m;

    int curr = 3;
    int ans = 0;
    while (curr <= m+1) {
        if (curr <= 50000) {
            ans += min(n/curr, curr-2);
            curr++;
            continue;
        }

        int dv = n/curr;
        int md = m+2;
        int lo = curr, hi = m+1;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            if (n/mid == dv) lo = mid + 1;
            else {
                md = mid;
                hi = mid - 1;
            }
        }
        ans += dv*(md - curr);
        curr = md;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}