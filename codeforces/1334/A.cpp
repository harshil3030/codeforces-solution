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
    for (auto &x : vp) {
        cin >> x.first >> x.second;
    }   
    map<int, int> mp;
    if (n == 1) {
        if (vp[0].second > vp[0].first) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    }else {
        if (vp[0].first < vp[0].second) {
            cout << "NO\n";
            return;
        }
        for (int i = 1; i < n; i++) {
            if (vp[i].first < vp[i-1].first || vp[i].second < vp[i-1].second || vp[i].first < vp[i].second) {
                cout << "NO\n";
                return;
            } else if (vp[i].first == vp[i-1].first && vp[i].second != vp[i-1].second) {
                cout << "NO\n";
                return;
            } else if ((vp[i].second - vp[i-1].second) > (vp[i].first - vp[i-1].first)) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}
