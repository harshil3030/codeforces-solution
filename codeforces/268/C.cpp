#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    int n,m;
    cin >> n >> m;
    cout << min(n,m) + 1 << "\n";
    for(int i = 0; i <= min(n,m); i++) {
        cout << i << " " << min(n,m) - i << "\n";
    }


    //    int curr = n+m;
//    vector<int> vis(curr+1, 0);
//    for(int i = 0; i <= 100; i++) {
//        if (i*i > curr) break;
//        vis[i*i] = 1;
//    }
//    vector<pair<int, int>> ans;
//    ans.push_back({0, 0});
//    vector<int> pos_sum;
//    for(int i = 1; i <= curr; i++) {
//        if (vis[i] == 1) continue;
//        else {
//            pos_sum.push_back(i);
//            for(int j = 1; j <= 100; j++) {
//                if (j*j + i > curr) break;
//                vis[j*j + i] = 1;
//            }
//        }
//    }
//
//    for(int i = 0; i < pos_sum.size(); i++) {
//        if (n >= pos_sum[i]) ans.push_back({pos_sum[i], 0});
//        else {
//            int rest = pos_sum[i] - n;
//            ans.push_back({n, rest});
//        }
//    }
//    cout << ans.size() << "\n";
//    for(auto &x : ans) {
//        cout << x.first << " " << x.second << "\n";
//    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}