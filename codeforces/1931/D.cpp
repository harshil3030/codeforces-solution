// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
    int n,x,y; cin >> n >> x >> y;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    
    // for (auto &x : v) cout << x << " "; cout << "\n";
    // cout << x << " " << y << "\n";
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        mp[{(v[i] % x), (v[i] % y)}]++;
    }   
    
    // for (auto &x: mp) {
        // cout << x.first.first << " " << x.first.second <<
        // " " << x.second <<  "\n";
    // }
    
    
    
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int req = x - (v[i] % x);
        if (req == x) req = 0;
        
        if (req == (v[i] % x)) {
            ans += (mp[{req, v[i] % y}] * (mp[{req, v[i] % y}] - 1))/2;
            mp[{req, v[i] % y}] = 0;
            mp[{v[i] % x, v[i] % y}] = 0;
            mp.erase({v[i] % x, v[i] % y});
            mp.erase({req, v[i] % y});
            continue;    
        }
        
        
        ans += ((mp[{req, v[i] % y}]) * mp[{v[i]%x, v[i]%y}]);
        mp[{req, v[i] % y}] = 0;
        mp[{v[i] % x, v[i] % y}] = 0;
        mp.erase({v[i] % x, v[i] % y});
        mp.erase({req, v[i] % y});
    }
    cout << ans << "\n";
}
