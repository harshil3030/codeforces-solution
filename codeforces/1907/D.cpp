#include <bits/stdc++.h>
using namespace std;
void solve();
int main () {
    int tt; cin >> tt;
    while (tt--) solve();
}

void solve() {
    
    int n; cin >> n;
    vector<pair<long long, long long>> vp(n);
    for (auto &x : vp) cin >> x.first >> x.second;
    long long l = 0;
    long long r = 1e9;
    auto can = [](long long x, vector<pair<long long, long long>> vp, int n) {
        long long ff = 0, ss = 0;
        for (int i = 0; i < n; i++) {
            ss = min(ss + x, vp[i].second);
            ff = max(ff - x, vp[i].first);
            if (ff > ss) return false;
        }
        return true;
    };
    int ans = -1;
    while (l <= r) {
        long long mid = (l + r)/2;
        if (can(mid, vp, n)) {
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << "\n";
}