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
    int n; cin >> n;
    string s,t; cin >> s >> t;
    int ff = 0, ss = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] != '1') ff++;
        else if (s[i] == '0' && t[i] == '1') ss++;
    }   

    int ans = min(ff,ss);
    ans += max(ff,ss) - min(ff,ss);
    cout << ans << "\n";
}
