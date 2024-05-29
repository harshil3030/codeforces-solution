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
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++) {
        vp[i].first = v[i];
        vp[i].second = i;
    }

    auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
    };
    sort(vp.begin(), vp.end(), comp);
    vector<int> inda;
    vector<int> indb;
   int tmpa = a;
   int tmpb = b;
   int k = 0;

   while (k < vp.size()) {
       if (tmpb < tmpa) {
        tmpb += b;
        indb.push_back(vp[k++].second);
       } else {
        tmpa += a;
        inda.push_back(vp[k++].second);
       }
    }
   cout << inda.size() << " ";
   for(auto &x : inda) {
    cout << x + 1 << " ";
   } cout << "\n";
   cout << indb.size() << " ";
   for(auto &x : indb) {
    cout << x + 1 << " ";
   } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}