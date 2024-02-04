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
    int n,x,m; cin >> n >> x >> m;
    int tmp = m;
    vector<pair<int,int>> vp;
    vp.push_back({x,x});
    while (tmp--) {
        int a,b; cin >> a >> b;
        for (auto &x : vp) {
            if (a > x.second || b < x.first) {
                continue;
            }else {
                vp.push_back({a,b});
                break;
            }
        }
    }   
    // for (auto &x : vp) cout << x.first << " " << x.second << "\n";
    // vp.erase(vp.begin(), vp.begin() + 1);
    int cnt = 0;
    int last = 0;
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size(); i++) {
        // cout << "here\n";
        // cout << last << " " << cnt << "\n";
        // cout << vp[i].first << " " << vp[i].second << "\n";
        if (last < vp[i].first) {
            last = vp[i].second;
            cnt += (vp[i].second - vp[i].first + 1);
        } else {
            if (last >= vp[i].second) continue;
            cnt += (vp[i].second - last);
            last = vp[i].second;
        }
    }
    cout << cnt << "\n";
}
