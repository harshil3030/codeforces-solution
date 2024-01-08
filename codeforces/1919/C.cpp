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
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int ans = 0;
    int l1 = 1e18, l2 = 1e18;

    for (int i = 0; i < n; i++) {
        if (v[i] < l1 && v[i] < l2) {
            if (l1 < l2) l1 = v[i];
            else l2 = v[i];
        } else if (v[i] > l1 && v[i] > l2) {
            if (l1 < l2) l1 = v[i];
            else l2 = v[i];
            ans += 1;
        } else {
            if (v[i] == l1) l1 = v[i];
            else if (v[i] == l2) l2 = v[i];
            else if (l1 < l2) {
                l2 = v[i];
            } else l1 = v[i];
        }
    }
    cout << ans << "\n";
}
 