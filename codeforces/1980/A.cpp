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
  map<char, int> mp;
  for(auto &x : s) mp[x]++;
  int need = 0;
  for(int i = 0; i < 7; i++) {
    char ch = 'A' + i;
    int curr = mp[ch];
    if (curr < m) need += m - curr; 
  } 
  cout << need << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}