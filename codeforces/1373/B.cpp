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
    string s; cin >> s;
    int n = s.length();
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') one++;
        else zero++;
    }   
    if (min(one, zero) % 2) {
        cout << "DA\n";
    }else cout << "NET\n";
}
