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
    string s;
    cin >> s;
    vector<int> ind(m);
    for(auto &x  : ind) cin >> x;
    string c;
    cin >> c;

    sort(c.begin(), c.end());
    sort(ind.begin(), ind.end());

    set<int> st;
    for(auto &x : ind) {
        st.insert(x);
    }

    int lo = 0;
    for(auto &x : st) {
        s[x-1] = c[lo++];
    }
    cout << s << "\n";

//    vector<pair<int, char>> vp;
//    for(int i = 0; i < m; i++) {
//        vp.push_back({ind[i], c[i]});
//    }
//    map<int, char> mp;
//    for(int i = m-1; i >= 0; i--) {
//        mp[vp[i].first - 1] = vp[i].second;
//    }
//
//    for(auto &x : mp) {
//        s[x.first] = x.second;
//    }
//    cout << s << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}