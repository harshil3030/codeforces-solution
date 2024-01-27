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
    // int n,m; cin >> n >> m;
       int n; cin >> n;
       vector<pair<int, int>> vp(n);
       for (auto &x : vp) {
         cin >> x.first >> x.second;
       }
       map<int, int> mp;
       for (int i = 1; i < n; i++) {
            mp[i] = max((int)0, (vp[i].first - vp[i-1].second));
       }  
       mp[0] = max((int)0,vp[0].first - vp[n-1].second);

       int sm = 0;
       for (auto &x : mp) sm += x.second;
       int mn = LLONG_MAX;
       for (int i = 0; i < n; i++) {
            mn = min(mn, (vp[i].first + (sm - mp[i])));
       }
       cout << mn << "\n";

}
