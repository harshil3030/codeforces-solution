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
    int mx = 0;
    int x1,y1,x2,y2,x3,y3,x4,y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    mx = max(abs(x1-x2), max(abs(x1 - x3), abs(x1 - x4)));
    cout << mx*mx << "\n";
}
