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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int mx  = 0;
    int sm = 0;

    for(int i = 0; i < min(33ll, n); i++) {
        mx += (v[i] >> (1 + i));
    }
    for(int i = 0; i < n; i++) {
        sm += v[i];
        sm -= k;
        int now = 0;
        for(int j = i + 1; j < min(i + 33, n); j++) {
            int curr = j - i;
            now += (v[j] >> curr);
        }
        mx = max(mx, sm + now);
    }

    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}