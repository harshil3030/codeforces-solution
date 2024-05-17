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
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    bool isone = false;
    if (v[n-1] == n) isone = true;
    for(int i = 1; i < n; i+=2) {
        if(v[i] == n) isone = true;
    }  

    vector<int> ans(n, 0);
    if(isone) {
        map<int, int> idx;
        for(int i = 1; i < n-1; i+=2) {
            idx[v[i]] = i;
        }
        int last = n;
        for(auto &x : idx) {
            ans[x.second] = last;
            last--;
        }
        ans[n-1] = last;
        last--;
        map<int, int> idx2;
        for(int i = 0; i < n-1; i+=2) {
            idx2[v[i]] = i;
        }

        for(auto &x : idx2) {
            ans[x.second] = last;
            last--;
        }

        for(auto &x: ans) {
            cout << x << " ";
        } cout << "\n";
    } else {
        map<int, int> idx;
        for(int i = 2; i < n-1; i+=2) {
            idx[v[i]] = i;
        }

        int last = n;
        for(auto &x : idx) {
            ans[x.second] = last;
            last--;
        }
        ans[0] = last;
        last--;
        map<int, int> idx2;
        for(int i = 1; i < n; i+=2) {
            idx2[v[i]] = i;
        }
        for(auto &x : idx2) {
            ans[x.second] = last;
            last--;
        }

        for(auto &x : ans) {
            cout << x << " ";
        } cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}