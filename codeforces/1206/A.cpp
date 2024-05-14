#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;

    set<int> st1, st2;
    for (int i= 0; i < n; i++) st1.insert(v[i]);
    for (int i = 0; i < m; i++) st2.insert(b[i]);



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!st1.count(v[i] + b[j]) && !(st2.count(v[i] + b[j]))) {
                cout << v[i] << " " << b[j] << "\n";
                return;
            }
        }
    }   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}