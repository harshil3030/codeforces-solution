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
  int n; cin >> n;
  vector<int> v(n);
  for(auto &x : v) cin >> x;
  vector<int> b;
  bool pref[n-1];
  bool suff[n-1];

  for(int i = 0; i < n-1; i++) {
    b.push_back(__gcd(v[i], v[i+1]));
  }

  for(int i = 0; i < n-1; i++) {
    if (i == 0) pref[i] = true;
    if (i != 0) {
        if (b[i] >= b[i-1]) {
            pref[i] = pref[i-1];
        } else {
            pref[i] = false;
        }
    } 
  }

  for(int i = n-2; i >= 0; i--) {
    if (i == n-2) suff[i] = true;
    else {
        if (b[i+1] >= b[i]) {
            suff[i] = suff[i+1];
        } else {
            suff[i] = false;
        }
    }
  }

  bool ok = false;
  for(int i = 0; i < n; i++) {
    if (i == n-1) {
       ok = ok | pref[i-2];
    } else if (i == 0) {
        ok = suff[i+1];
    }else {
        int curr = __gcd(v[i-1], v[i+1]);
        //effect b[i] & b[i-1]
        if (i-2 >= 0) {
            if (b[i-2] > curr) continue;
        }
       if (i + 1 <= n-2) {
            if (curr > b[i+1]) continue;
        }
      int final = 0;
      if (i - 2 >= 0) {
        if (pref[i-2] == true) final++;
     } else final++;
        
      if (i+1 <= n-2) {
         if (suff[i+1] == true) final++;
      } else final++;
      ok = ok | (final == 2);
    } 
  } 

  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}