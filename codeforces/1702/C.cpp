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
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[v[i]].push_back(i);
    }
    while (k--) {
        int p,q; cin >> p >> q;
        if (mp[q].empty() || mp[p].empty()) {
            cout << "NO\n";
        } else if (mp[p][0] <= mp[q][mp[q].size() - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
