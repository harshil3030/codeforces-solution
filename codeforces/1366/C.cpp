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
    int n,m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for (auto &x : v) {
        for (auto &y : x) {
            cin >> y;
        }
    }

    vector<vector<int>> cnt(n+m-1, vector<int> (2,0));
    int mxlvl = (n+m-1)/2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lvl = (i + j);
            if (v[i][j] == 1) cnt[lvl][1]++;
            else cnt[lvl][0]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < cnt.size()/2; i++) {
        int ffone = cnt[i][1];
        int ffzero = cnt[i][0];
        int ssone = cnt[(m+n-2) - i][1];
        int sszero = cnt[(m+n-2) - i][0];

        int totone = ffone + ssone;
        int totzero = ffzero + sszero;
        ans += min(totone, totzero); 
    }
    cout << ans << "\n";
}
