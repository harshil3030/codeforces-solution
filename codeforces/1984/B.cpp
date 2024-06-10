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
  string s;
  cin >> s;
  int n = s.length();
  if (s[n-1] == '9' || s[0] != '1') {
    cout << "NO\n";
    return;
  }

  for(int i = 1; i < n-1; i++) {
    if (s[i] == '0') {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}