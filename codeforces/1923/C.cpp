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
    int n,q; cin >> n >> q;
    vector<int> v(n);
    for (auto &x :v) cin >> x;
    
    int pref[n + 1];
    pref[0] = 0;
    int zero[n  +1];
    zero[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i-1] - 1;
        zero[i] = zero[i-1] + (v[i-1] == 1);
    }
    
    
    
    
    
    
    while (q--) {
        int x,y; cin >> x >> y;
        if (y - x + 1 == 1) {
            cout << "NO\n";
            continue;
        }
        if (pref[y] - pref[x-1] >= (((zero[y] - zero[x-1])))) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }   
}
