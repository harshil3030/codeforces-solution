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
    vector<int> v(3);
    int n,m,z;
    cin >> n >> m >> z;
    v[0] = n, v[1] = m, v[2] = z;
    sort(v.begin(), v.end());
    int a = v[0], b = v[1];
    int tot = (v[0]+v[1]+v[2])/3;
    cout << min(a+b, tot) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}