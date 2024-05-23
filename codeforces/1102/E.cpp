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
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<int> vis(n, 0);
    vector<int> st(n, 0);
    map<int, vector<int>> freq;
    for(int i = 0; i < n; i++) {
        freq[v[i]].push_back(i);
    }   
    map<int, int> marked;
    for(int i = 0; i < n; i++) {
        if (freq[v[i]].size() == 1 || marked[v[i]] == 1) continue;

        marked[v[i]]++;
        int firstInd = freq[v[i]][0];
        int lastInd = freq[v[i]][freq[v[i]].size() - 1];
        vis[firstInd] += 1;
        st[firstInd] += 1;
        st[lastInd] += -1;
        if (lastInd + 1 > n-1) continue;
        vis[lastInd + 1] += -1;
    }

    for(int i = 1; i < vis.size(); i++) {
        vis[i] += vis[i-1];
        st[i] += st[i-1];
    }
    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        if (st[i] == 0) cnt++;
    }


    // for(int i = 1; i < vis.size(); i++) {
    //     if (vis[i] == 0) {
    //         cnt++;
    //     } 
    // }
    // bool zero = false;
    // for(int i = 0; i < vis.size(); i++) {
    //     if (vis[i] != 0) {
    //         if (zero) {
    //             cnt++;
    //             zero = false;
    //         }
    //     } else {
    //         zero = true;
    //     }
    // }

    // for(auto &x : vis) {
    //     cout << x << " ";
    // } cout << "\n";

    // cout << "\n";
    // for(auto &x : st) {
    //     cout << x << " ";
    // } cout << "\n";


    //x^y
    auto bin_expo = [&](int x, int y, int mod) -> int {
        int res = 1;
        while (y > 0) {
            if (y % 2) {
                res = ((res % mod) * (x % mod)) % mod;
            }
            x = x*x;
            x %= mod;
            y/=2;
        }
        return res;
    };
    cout << bin_expo(2, cnt, mod) % mod << "\n"; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}