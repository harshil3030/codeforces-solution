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
 int x,m;
 cin >> x >> m;
 vector<int> ans;
 int clz = __builtin_clzll(m);
 int fbit = 63 - clz;  
 if ((1ll << fbit) & x) {
  cout << 1 << "\n";
  cout << x << " " << m << "\n";
  return;
 }

 int clz2 = __builtin_clzll(x);
 int fbitx = 63 - clz2;
  bool ok = false;
  int till = fbit + 1;
  for(int bit = fbit + 1; bit < fbitx; bit++) {
    if ((1ll << bit) & x) {
      till = bit;
      ok = true;
      break;
    }
  }

  if (!ok) {
    cout << -1 << "\n";
    return;
  }

  int z = m;
  for(int i = fbit + 1; i <= till; i++) {
    z ^= (1ll << i);
  }

  cout << 2 << "\n";
  cout << x << " " << z << " " << m << "\n"; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

