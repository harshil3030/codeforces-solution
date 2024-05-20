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
    int x,y;
    cin >> x >> y;
    int mn = (y + 1)/2;
    int rest = 7*mn;
    if (y % 2) {
        rest += 4;
    }         
    if (rest >= x) {
        cout << mn << "\n";
    }else {
        int xrest = x - rest;
        int ext = xrest/15;
        if (xrest % 15 != 0) ext++;
        cout << mn + ext << "\n";
    }            
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}