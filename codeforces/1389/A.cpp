// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
       int x,y; cin >> x >> y;
       int l = x;
       int l2 = 2*x;
       if (l >= x && l <= y && l2 >= x && l2 <= y) {
           cout << l << " " << l2 << "\n";
       }else {
           cout << -1 << " " << -1 << "\n";
       }
}
