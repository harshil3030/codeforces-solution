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
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &x : v) cin >> x;
  int ff = v[0];
  int la = v[n-1];
  if (ff != la) {
    cout << "YES\n";
    vector<char> ans(n, 'R');
    ans[1] = 'B';
    for(auto &x : ans) cout << x;
        cout << endl;
  }else {
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