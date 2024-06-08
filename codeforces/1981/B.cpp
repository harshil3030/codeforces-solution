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
  bool ok = false;
  int ans = 0;
  for(int b = 62; b >= 0; b--) {
    if ((1ll << b) & n) {
      ok = true;
      continue;
    }
    int cnt = 0;
    for (int rb = 0; rb < b; rb++) {
      if ((1ll << rb) & n) {
        cnt += (1ll << rb);
      }
    }

    int ff = 1e12, ss = 1e12;
    if (ok) {
      ff = cnt+1;
    }
    ss = (1ll << b) - cnt;
    int mn = min(ff, ss);
    if (mn <= m) {
      ans += (1ll << b);
    }
  }
  ans += n;
  cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}