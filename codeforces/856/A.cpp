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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    bool ok = true;

    map<int, int> diff;
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++) {
        if (v[i] == v[i+1]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            diff[v[j] - v[i]]++;
        }
    }

    vector<int> b;
    for(int i = 1; i <= 1e6; i++) {
        int cnt = 0;
        bool ok = true;
        for(int j = i; j <= 1e6; j+=i) {
            if (diff.count(j)) ok = false;
            else {
                cnt++;
            }
            if (!ok) break;
            if (cnt == 99) break;
        }

        if (ok) {
            for(int j =0; j < n; j++) {
                b.push_back(j*i+1);
            }
        }
        if(ok) break;
    }



    cout << "YES\n";
    for(auto &x : b) {
        cout << x << " ";
    } cout << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}