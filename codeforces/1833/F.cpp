#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();
int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
       int n,m; cin >> n >> m;
       vector<int> v(n); for (auto &x : v) cin >> x;
       map<int, int> mp;
       for (auto &x : v) mp[x] += 1;
       int final = 0;

       set<int> st;
       for (auto &x : v) st.insert(x);
       vector<int> temp;
       temp.insert(temp.end(),st.begin(),st.end());

       if (m == 1) {
            cout << n << "\n";
            return;
       }else {
            auto bin_expo = [&](int x, int y, int mod) {
                int ans = 1;
                while (y > 0) {
                    if (y % 2) ans = (ans * x) % mod;
                    y/=2; x = ((x % mod) * (x % mod)) % mod;
                }
                return ans;
            };
            auto inv = [&](int x, int mod) {
                return bin_expo(x,mod - 2,mod) % mod;
            };
            int ff = 0, ss = 1;
            int cnt = 1; int ans = mp[temp[ff]] % mod;
            while (ff <= ss && ss < temp.size()) {
                if (temp[ss] - 1 == temp[ss - 1]) {
                    cnt++;
                    ans *= (mp[temp[ss]] % mod);
                    // cout << ans << " " << ss << "  here\n";
                    ans = ans % mod;
                    while (cnt > m) {
                        cnt--;
                        ans = ((ans % mod) * inv(mp[temp[ff]], mod)) % mod;
                        ff++;
                    }
                    if (cnt == m) {
                        final += (ans % mod);
                        final = final % mod;
                    }
                    ss++;
                }else {
                    cnt = 1;
                    ff = ss;
                    ans = mp[temp[ss]] % mod;
                    ss++;
                }
            }
            cout << (final % mod) << "\n";
       }


}
