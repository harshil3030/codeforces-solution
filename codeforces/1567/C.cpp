#include<bits/stdc++.h>
#include "string"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    int n;
    cin >> n;
    string s = to_string(n);
    int len = s.length();
    string t1 = "";
    string t2 = "";
    for(int i = 0; i < len; i+=2) {
        t1 += s[i];
    }
    for(int i = 1; i < len; i+= 2) {
        t2 += s[i];
    }
    int x1 = 0, x2 = 0;
    for(int i = 0; i < t1.length(); i++) {
        x1  = (x1 * 10) + (t1[i] - '0');
    }
    for(int i = 0; i < t2.length(); i++) {
        x2 = (x2 * 10) + (t2[i] - '0');
    }
    cout << (x1+1)*(x2+1)-2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}