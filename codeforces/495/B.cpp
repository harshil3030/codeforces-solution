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

    if (n == 0) {
        if (m == 0) {
            cout << "infinity\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }

    if (n == m) {
        cout << "infinity\n";
        return;
    }

    set<int> fct;
    for(int j = 1; j*j <= n; j++) {
        if (n % j == 0) {
            fct.insert(j);
           if (j != 1) fct.insert(n/j);
        }
    }

    int last = *fct.rbegin();

    int till = n - last;
    if (m >= 0 && m <= till) {
        int cnt = 0;
        int ff = n-m;
        int prime = ff;
        set<int> p;

        for(int j = 1; j*j <= prime; j++) {
            if (prime % j == 0) {
                p.insert(j);
                p.insert(prime/j);
            }
        }
        for(auto &x : p) {
            if (x > m) cnt++;
        }
        cout << cnt << "\n";
    } else {
        cout << 0 << "\n";
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
    solve();
    return 0;
}