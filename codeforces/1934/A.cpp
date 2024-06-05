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
 vector<int> v(n);
 int mx = 0;
 for(auto &x : v) cin >> x;
 sort(v.begin(), v.end());
 mx = abs(v[0] - v[n-1]) + abs(v[n-1] - v[1]) + abs(v[1] - v[n-2]) + abs(v[n-2] - v[0]);
 cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}