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
  vector<int> a(n), b(n);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;
  map<int, int> d;
  map<int, int> freq;
  vector<int> reald;
  int m; cin >> m;
  for(int i = 0; i < m; i++) {
    int x; cin >> x;
    reald.push_back(x);
    d[x] = i;
    freq[x]++;
  }

  for(int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
        if (freq[b[i]] == 0) {
            cout << "NO\n";
            return;
        }
        freq[b[i]]--;
    }
  }

  int last = reald[m-1];
  bool ok = false;
  for(auto &x : b) {
    if (x == last) ok = true;
  }

  if (!ok) {
    cout << "NO\n";
    return;
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