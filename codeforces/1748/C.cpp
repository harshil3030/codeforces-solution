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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    
    int pref[n + 1];
    pref[0] = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i-1];
    }   
    
    
    
    int flg = 1;
    int ans = 0;
    int mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mp[pref[i+1]]++;
        mx = max(mx, mp[pref[i+1]]);
        if (v[i] == 0) {
            ans += mx;
            mp.clear();
            mx = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (v[i-1] == 0) break;
        if (pref[i] == 0) ans++;
    }
    
    cout << ans << "\n";
}
