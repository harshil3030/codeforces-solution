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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        vp[i].first = a;
        vp[i].second = b;
    }
    auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
        return  p1.second > p2.second;
    };
    sort(vp.begin(), vp.end(), comp);

    int lo = 0, hi = n-1;
    int ans = 0;
    int items_bought = 0;
    while (lo <= hi) {
        int req = vp[hi].second;
        if (req <= items_bought) {
            ans += vp[hi].first;
            items_bought += vp[hi].first;
            vp[hi].first = 0;
            hi--;
            if (hi >= lo) req = vp[hi].second;
            else break;
        }
        if (lo <= hi) {
            if (items_bought < vp[hi].second) {
                if (vp[lo].first + items_bought < vp[hi].second) {
                    ans += vp[lo].first*2;
                    items_bought += vp[lo].first;
                    lo++;
                } else {
                    int req_items = vp[hi].second - items_bought;
                    vp[lo].first -= req_items;
                    ans += req_items*2;
                    items_bought += req_items;
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}