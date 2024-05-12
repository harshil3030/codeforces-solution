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
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;

    auto lcm = [&](int a, int b) -> int {
        return ((a*b)/__gcd(a,b));
    };

    if (n <= 3) {
        int mul = 1;
        for (int i = 1; i <= n; i++) mul*=i;
            cout << mul << "\n";
    } else {
       cout << max({lcm(n, lcm(n-1,n-3)), lcm(n, lcm(n-1,n-2)), lcm(n-1, lcm(n-2,n-3))});
       cout << "\n";
    }
}
