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
    int n,k,d; cin >> n >> k >> d;
    vector<int> v(n);
    vector<int> kth(k);
    int flg = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]) flg = 1;
    }
    for(auto &x : kth) cin >> x;

    if (!flg) {
        cout << d/2 << "\n";
        return;
    }
    int mx = d/2-1;
    int poi = 0;
    for(int i = 0; i < n; i++) {
        poi += (v[i] == (i + 1));
    }   
    for (int day = 1; day <= min(d, 2*n+1); day++) {
        mx = max(mx, poi + (d - day)/2);
        poi = 0;
        for(int i = 0; i < kth[(day - 1) % k]; i++) {
            v[i] += 1;
        }
        for(int i = 0; i < n; i++) {
            poi += (v[i] == (i + 1));
        }
    }
    cout << mx << endl;
}
