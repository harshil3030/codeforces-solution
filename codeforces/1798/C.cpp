#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
#define _lcm(a,b) (a*b)/__gcd(a,b)
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
    vector<pair<int, int>> vp(n);
    for (auto &x : vp) {
        cin >> x.first >> x.second;
    }
    int cnt = 1;
    int gcd = vp[0].first * vp[0].second;
    int lcm = vp[0].second;
    for (int i = 1; i < n; i++) {
        lcm = _lcm(lcm, vp[i].second);
        gcd = __gcd(gcd, vp[i].first * vp[i].second);
        if (gcd % lcm != 0) {
            cnt++;
            lcm = vp[i].second;
            gcd = vp[i].first * vp[i].second;
        }
    }
    cout << cnt << "\n";
}
