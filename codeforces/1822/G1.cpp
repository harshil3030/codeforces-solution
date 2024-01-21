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
    int n; cin >> n;
    vector<int> v(n); for (auto &x : v) cin >> x;
    map<int, int> mp;
    for (auto &x : v) mp[x] += 1;
    int ans = 0;
    for (auto &x : mp) {
        int y = x.first;
        if (x.second > 2) {
            ans += ((x.second) * (x.second - 1) * (x.second - 2));
        }
        for (int i = 2; i <= 1000; i++) {
            int y2 = y*i;
            if (y2 > 1e6) break;
            int y3 = y2*i;
            if (y3 > 1e6) break;
            if(mp.find(y2) != mp.end() && mp.find(y3) != mp.end()) {
                ans += mp[y]*mp[y2]*mp[y3];
            }   
        }
    }
    cout << ans << "\n";   
}
