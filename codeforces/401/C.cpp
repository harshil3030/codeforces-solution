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
    cin >> m >> n;
    if (n > m*2+2 || n < m-1) {
        cout << -1 << "\n";
        return;
    }
    int curr_zeros = m;
    int curr_ones = n;
    if (curr_zeros >= curr_ones) {
        int tmp = 0;
        for(int i = 0; i < n+m; i++) {
            cout << tmp;
            tmp = tmp^1;
        }cout << "\n";
        return;
    }
    string ans = "";
    while (curr_zeros > 0 && curr_ones > 0) {
        if (curr_ones > curr_zeros) {
            ans += "11";
            ans += "0";
            curr_zeros -= 1;
            curr_ones -= 2;
        } else {
            ans += "1";
            ans += "0";
            curr_zeros -= 1;
            curr_ones -= 1;
        }
    }
    if (curr_zeros > 0) {
        for(int i = 0; i < curr_zeros; i++) ans += "0";
    }
    if (curr_ones > 0) {
        for(int i = 0; i < curr_ones; i++) ans += "1";
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}