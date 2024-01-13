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
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<int, int> mp;
    for (auto &x : v) mp[x]++;

    int mx = *max_element(v.begin(),v.end());
    int f[mx+1];
    f[0] = 0; f[1] = mp[1];

    for (int i = 2; i <= mx; i++) {
        f[i] = max(f[i-1], f[i-2]+(mp[i]*i));
    }
    cout << f[mx] << "\n";
}
