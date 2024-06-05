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
 vector<int> v(5);
 v[0] = 1;
 v[1] = 3;
 v[2] = 6;
 v[3] = 10; 
 v[4] = 15;

 int coins = 0;

 if (n > 30) {
  int times = n/30;
  coins += (times*2);
  n %= 30;
  if (n < 30) {
    n += 30;
    coins -= 2;
  }
 }
 
 int dp[5][n+1];
 for(int i  = 0; i < 5; i++) {
  for (int j  = 0; j <= n; j++) {
    dp[i][j] = 1e12;
  }
 }

 for(int i = 0; i < 5; i++) {
  dp[i][0] = 0;
 }

 for(int ind = 0; ind < 5; ind++) {
  for(int tar = 0; tar <= n; tar++) {
    if (tar >= v[ind]) {
      if (ind == 0) dp[ind][tar] = 1 + dp[ind][tar - v[ind]];
      else dp[ind][tar] = min(1 + dp[ind][tar-v[ind]], dp[ind - 1][tar]);
    } else {
      if (ind > 0) dp[ind][tar] = dp[ind - 1][tar];
    }
  }
 }

 coins += dp[4][n];
 cout << coins << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}