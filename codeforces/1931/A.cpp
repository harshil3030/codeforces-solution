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
    int n; cin >> n;
    string s;
    for (int i = 2; i >= 0; i--) {
        if (i == 2 && n >= 28) {
            s += 'z';
            n -= 26;
        } else if (i == 2) {
            s += ('a' + (n-3));
            n -= (n-2);
        } else if (i == 1 && n >= 27) {
            s += 'z';
            n -= 26;
        } else if (i == 1) {
            s += ('a' + (n-2));
            n -= (n-1);
        } else if (i == 0 && n >= 26) {
            s += 'z';
            n = 0;
        } else {
            s += ('a' + (n-1));
            n = 0;
        }
    }
    reverse(s.begin(), s.end());  
    cout << s << "\n"; 
}
