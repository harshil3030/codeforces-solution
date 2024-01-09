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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<int, set<int>> mp;
    // for (auto &x : v) fun(mp, x);   
    map<int, int> freq;
    
    vector<int> ans;
    int orr = 0; int mx = 0;
    for (int i = 0; i <= 30; i++) {
        int neworr = orr; int ele = -1;
        for (int i = 0; i < n; i++) {
            if ((orr | v[i]) > neworr && freq[v[i]] == 0) {
                neworr = orr | v[i];
                ele = v[i];
            }
        } 
        if (ele != -1) {
            freq[ele] += 1;
            cout << ele << " ";
        }orr = orr | ele;
    }
    for (auto &x: v) {
        if (freq[x] > 0) freq[x]--;
        else cout << x << " ";
    } cout << "\n";
}
