#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
 int n, m;
        cin >> n >> m;
        vector<int> p(n + m + 1), t(n + m + 1);
        for(auto &x : p) cin >> x;
        for(auto &x : t) cin >> x;
        
        long long p_ed = 0, p_et = 0;
        int p_cd = 0, p_ct = 0;
        vector<int> pm1(p.size()), pm2(p.size());
        for(auto &x : p) {
        	x += 1, x -= 1;
        }
        for(auto &x : t) {
        	x += 1; x -=1;
        }
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] > t[i] && p_cd <= n) {
                p_ed += p[i];
                p_cd += 1;
                pm1[i] = 1;
            } else if (p[i] < t[i] && p_ct < m) {
                p_ed += t[i];
                p_ct += 1;
                pm1[i] = 0;
            } else if (p_cd <= n) {
                p_ed += p[i];
                p_cd += 1;
                pm1[i] = 1;
            } else {
                p_ed += t[i];
                p_ct += 1;
                pm1[i] = 0;
            }
        }
        
        p_ct = 0;
        p_cd = 0;
        
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] < t[i] && p_ct <= m) {
                p_et += t[i];
                p_ct += 1;
                pm2[i] = 0;
            } else if (p[i] > t[i] && p_cd < n) {
                p_et += p[i];
                p_cd += 1;
                pm2[i] = 1;
            } else if (p_ct <= m) {
                p_et += t[i];
                p_ct += 1;
                pm2[i] = 0;
            } else {
                p_et += p[i];
                p_cd += 1;
                pm2[i] = 1;
            }
        }
        
        for (int i = 0; i < p.size(); ++i) {
            long long v1 = 0;
            if (pm1[i] == 1) {
                v1 = p_ed - p[i];
            } else if (pm2[i] == 0) {
                v1 = p_et - t[i];
            }
            cout << v1 << " ";
        }
        cout << "\n";  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}