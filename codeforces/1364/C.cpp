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
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> b(n, -1);
    map<int, int> vis;
    int l = 0;
    for(int i = n-1; i > 0; i--) {
        if (a[i] != a[i-1]) {
            b[i] = a[i-1];
            vis[a[i]] = 1;
        } else {
            vis[a[i]] = 1;
        }
    }
    vis[a[0]] = 1;
    for(int i = 0; i < n; i++) {
        if (b[i] == -1) {
            while (vis[l] == 1) l++;
            b[i] = l;
            l++;
        }
    }

    for(int i = 0; i < n; i++) {
        if (a[i] > i+1) {
            cout << -1 << "\n";
            return;
        }
    }

    for(auto &x : b) cout << x << " ";
    cout << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}