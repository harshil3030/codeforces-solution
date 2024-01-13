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
    int n,k,x; cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int pref[n+1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + v[i-1];
    int suff[n+1];
    suff[n] = 0;
    for (int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + v[i];
    
    int mx = pref[max((n-x),(int)0)] - (pref[n] - pref[max((n-x),(int)0)]);
    for (int i = n-1; i >= max((int)0,n-k); i--) {
        mx = max(mx, (pref[max((i-x),(int)0)] - (pref[i] - pref[max((i-x),(int)0)])));
    }       
    cout << mx << "\n";
}
