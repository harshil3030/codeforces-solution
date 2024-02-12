// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
    int x,y,z; cin >> x >> y >> z;
    int req = (((y*z)+z)-1);   
    x--;
    int tot = req % x ? 1 : 0;
    tot += req/x;
    tot += z;
    cout << tot << "\n";
}
