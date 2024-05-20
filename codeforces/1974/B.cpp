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
   string s;
   cin >> s;
   string t;
   map<char,int> mp;
   for(int i = 0; i < n; i++) {
      mp[s[i]]++;
      if (mp[s[i]] == 1) {
         t += s[i];
      }
   }  
   sort(t.begin(), t.end());
   map<char, char> change;
   int m = t.length();
   for(int i = 0; i < m; i++) {
      change[t[i]] = t[m-1-i];
   }
   string final;
   for(int i = 0; i < n; i++) {
      final += change[s[i]];
   }
   cout << final << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}