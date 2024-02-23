#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
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
    vector<int> a(n);
    vector<int> v(n);
    for (auto &x : a) cin >> x;
    for (auto &x : v) cin >> x;
    
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        v[i] = abs(v[i]);
        vp[i].first = v[i];
        vp[i].second = a[i];
    }   
    
    auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
      if (p1.first == p2.first)  return p1.second < p2.second;
      return p1.first < p2.first;
    };
    
    sort(vp.begin(), vp.end(), comp);
    
    int pow = 0;
    int close = 0;
    for (int i = 0; i < n; i++) {
        // if (vp[i].second > pow + (vp[i].first - close - 1)*k) {
            // cout << "NO\n";
            // return;
        // }
        pow -= vp[i].second;
        pow += (vp[i].first - close) * k;
        close = vp[i].first;
        if (pow < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
