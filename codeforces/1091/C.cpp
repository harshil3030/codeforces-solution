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
    int n; cin >> n;
    set<int> res;
    auto test = [&](int tar) {
        int leap = n/tar;
        res.insert((leap * (2 + (leap-1)*tar))/2);
    };
    for(int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            test(i);
            test(n/i);
        }
    }

    for(auto &x : res) cout << x << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}