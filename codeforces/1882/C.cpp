#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
    for (auto &x : v) cin >> x;
    int sm = 0;
    for (auto &x : v) if (x > 0) sm += x;

    if (n == 1) {
        cout << ((v[0] > 0) ? v[0] : 0) << "\n";
        return;
    }
    if (v[0] < 0 && v[1] > 0) {
        sm = max(v[0] + sm, sm - v[1]);
    }
    cout << sm << "\n";
}
