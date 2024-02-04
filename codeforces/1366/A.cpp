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
    int a,b; cin >> a >> b;
    if (a >= 2*b) {
        cout << b << "\n";
    } else if (b >= 2*a) {
        cout << a << "\n";
    } else if (a == b) {
        cout << (a+b)/3 << "\n";
    }  else {
        int diff = max(a,b) - min(a,b);
        if (a < b) a -= diff, b = a;
        else b -= diff, a = b;
        cout << diff + (a+b)/3 << "\n";
    }
}
