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
  string s,t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  bool ok = true;
  if (t.length() > s.length()) {
    ok = false;
  } else {
    for(int i = 0; i < min(n, m); i++) {
      if (s[i] > t[i]) {
        break;
      } else if (s[i] < t[i]) {
        ok = false;
        break;
      }
    }
  }
    if (!ok) {
      swap(s, t);
      swap(n, m);
    } 

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int idx = -1;
    for (int i = 0; i < m; i++) {
      if (t[i] < s[i]) {
        swap(t[i], s[i]);
      }
      if (t[i] != s[i]) idx = i;
    }

    if (idx != -1) {
      if (m < n) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        cout << s << "\n" << t << "\n";
        return;
      }

      if (t[idx] > s[idx]) {
        swap(t[idx], s[idx]);
      }
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    cout << s << "\n" << t << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}