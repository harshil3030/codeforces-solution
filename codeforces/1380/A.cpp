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
    vector<int> v(n);
    for (auto &x : v )cin >> x;
    vector<pair<int, int>> prefmx(n + 1);
    vector<pair<int, int>> suffmx(n + 1);

    int mx = INT_MAX;
    int in = 0;
    for (int i = 0; i < n; i++) {
        prefmx[i].first = mx;
        prefmx[i].second = in;
        if (v[i] < mx) {
            mx = v[i];
            in = i;
        }
    }
    mx = INT_MAX;
    in = n-1;
    for (int i = n-1; i >= 0; i--) {
        suffmx[i].first = mx;
        suffmx[i].second = in;
        if (v[i] < mx) {
            mx = v[i];
            in = i;
        }
    }

    // for (auto &x : prefmx) cout << x.first << " "; cout << "\n";
    // for (auto &x : suffmx) cout << x.first << " "; cout << "\n";



    for (int i = 1; i < n-1; i++) {
        if (prefmx[i].first < v[i] && suffmx[i].first < v[i]) {
            cout << "YES\n";
            cout << prefmx[i].second + 1 << " " << i + 1 << " " << suffmx[i].second + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}
