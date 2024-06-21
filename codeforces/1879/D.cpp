#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 998244353;

int sumh(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
        a += mod;
    return a;
}

int mul(int a, int b) {
    return (a * 1LL * b) % mod;
}


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int ans = 0;
    for(int b = 0; b <= 29; b++) {
        int sum[2]; int cnt[2];
        sum[0] = sum[1] = 0; cnt[0] = 1, cnt[1] = 0;
        int x = 0;
        int got = 0;
        for(int i = 0; i < n; i++) {
            x = x ^ ((v[i] >> b) & 1);
            assert(x <= 1);

            int multi = ((i + 1) * cnt[x^1]) % mod;
            got += multi - sum[x^1];
            got%=mod;
            cnt[x]++;
            sum[x] += (i + 1);
        }
        ans = ans + (((1ll << b) % mod) * (got % mod)) % mod;
        if (ans < 0) ans += mod;
        ans %= mod;
    }
    
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}