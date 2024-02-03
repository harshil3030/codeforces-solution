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
    int x,y; cin >> x >> y;
    int a,b; cin >> a >> b;
    int diff = abs(x-y);
    int mn  = min(x,y);
    if (a*2 > b) {
        cout << diff*a + mn*b << "\n";
    }else {
        cout << a*(x+y) << "\n";
    }
}
