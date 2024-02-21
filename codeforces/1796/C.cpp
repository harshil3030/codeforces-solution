#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 998244353;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,m; cin >> n >> m;
    int ff = n;
    int mxsize = 1;
    
    for (int i = 1; i < 32; i++) {
        if ((ff << i) <= m) {
            mxsize = i+1;
        } else break;
    }
    
    int peak = m/(1 << (mxsize-1));
    int ans = peak - ff + 1;
    
    peak = 1 << (mxsize - 1);
    peak /=2;
    peak *= 3;
    
    if (peak > 0)
    ans += ((max(0ll, (m/peak) - ff + 1ll) % mod) * ((mxsize - 1) % mod)) % mod;
    ans %= mod;
    
    cout << mxsize << " " << ans << "\n";
    
    
}
