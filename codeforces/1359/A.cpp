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
    int n,m,k; cin >> n >> m >> k;
    int tot = min(n/k,m);
    m -= tot;

    k--;
    if (m == 0) {
        cout << tot << "\n";
        return;
    }
    int otherMax =min(m/k + (m%k ? 1 : 0), n/k);
    cout << abs(tot - otherMax) << "\n";
}
