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
    vector<pair<int, int>> vp(n);
    vector<int> extra;
    for (auto &x : vp) {
        cin >> x.first >> x.second;
        if (x.first == 3) {
            extra.push_back(x.second);
        }
    }

    int lo = 1; int hi = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        
            if (vp[i].first == 1) {
                lo = max(lo, vp[i].second);
            }else if(vp[i].first == 2) {
                 hi = min(hi,vp[i].second);
            }
        
    }
    int sm = 0;
    int diff = hi - lo + 1;

    for (int i = 0; i < extra.size(); i++) {
        if (extra[i] >= lo && extra[i] <= hi) {
            diff--;
        }
    }
    cout << max((int)0,diff) << "\n";
}
