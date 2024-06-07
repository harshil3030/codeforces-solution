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
  int n, f, k;
  cin >> n >> f >> k;
  vector<int> v(n);
  for(auto &x : v) cin >> x;
  vector<pair<int, int>> vp(n);
  int ini = 0;
  int st = 0;

  for(int i = 0; i < n; i++) {
    if (v[i] == v[f-1]) ini++;
  }

  for(int i = 0; i < n; i++) {
    vp[i].first = v[i];
    vp[i].second = i;
  } 
  sort(vp.rbegin(), vp.rend());

  for(int i = 0; i < k; i++) {
    if (vp[i].first == v[f-1]) {
      st++;
    }
  }

  if (ini == st) {
    cout << "YES\n";
  } else if (st == 0) {
    cout << "NO\n";
  } else {
    cout << "MAYBE\n";
  }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}