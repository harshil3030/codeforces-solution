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
    vector<vector<int>> v(n, vector<int> (m));
    for(auto &x : v) {
        for(auto &y : x) {
            cin >> y;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            int left = -1000, right = -1000, bottom = -1000, top = -1000;
            if (j-1 >= 0) left = v[i][j-1];
            if (i-1 >= 0) top = v[i-1][j];
            if (i + 1 <= n-1) bottom = v[i+1][j];
            if (j + 1 <= m-1) right = v[i][j+1];

            int mx = max({left, right, bottom, top});
            if (mx >= v[i][j]) continue;
            v[i][j] = mx;
        }
    }

    for(auto &x : v) {
        for(auto &y : x) {
            cout << y << " ";
        } cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}