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
    map<int,int> mp;
    for (auto &x : v) mp[x]++;
    int half = ceil(mp.size()/2.0);
    int mn = max((int)1,half);
    
    int cnt = 0;
    int cntdbl = 0;
    for (auto &x : mp) {
        if (x.second == 1) cnt++;
        if (x.second >= 2) cntdbl++;
    }
    int shalf = ceil(cnt/2.0);
    mn = max(cntdbl + shalf, mn);
    cout << mn << "\n";
}
