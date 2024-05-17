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
   vector<vector<int>> bit(n+1, vector<int> (21, 0));

   for(int i = 1; i <= n; i++) {
      int ele = v[i-1];
      bit[i] = bit[i-1];
      for (int bits = 0; bits <= 20; bits++) {
         if ((ele >> bits) & 1) {
            bit[i][bits]++;
         }
      }
   }

   // int mx = -1;
   // for(int b = 0; b <= 20; b++) {
   //    vector<int> temp;
   //    temp.push_back(0);
   //    for(int i = 1; i <= n; i++) {
   //       if ((v[i-1] >> b) & 1) temp.push_back(i);
   //    } temp.push_back(n+1);
   //    if(temp.size() == 2) continue;
   //    for (int j = 1; j < temp.size(); j++) {
   //       mx = max(mx, temp[j] - temp[j-1]);
   //    }
   // }

   // if (mx == -1) {
   //    cout << n << "\n";
   // } else {
   //    cout << mx << "\n";
   // }

   // for(int i = 1; i <= n; i++) {
   //    for(int b = 0; b <= 20; b++) {
   //       cout << bit[i][b] << " ";
   //    } cout << "\n";
   // } cout << "\n";
   auto check = [&](int jump) {
      // for(int jump = 1; jump <= n; jump++) {
         bool ok = true;
         vector<int> temp = bit[jump];
       
         for (int i = jump; i <= n; i++) {
            vector<int> temp2 = bit[i];
            
            for(int b = 0; b <= 20; b++) {
               temp2[b] -= bit[i-jump][b];
            }
            
            for(int b = 0; b <= 20; b++) {
               if (temp[b] > 0) {
                  if (temp2[b] <= 0)ok =  false;
               } else {
                  if (temp2[b] > 0) ok = false;
               }
            }

            if (!ok) return false;
         }

         return true;
         // if(ok) {
         //    cout << jump << "\n";
         //    return;
         // }  
      // }
   };
   int lo = 1, hi = n;
   int ans = n;
   while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (check(mid)) {
         ans = mid;
         hi = mid - 1;
      } else {
         lo = mid + 1;
      }
   }

   cout << ans << "\n";
   // cout << n << "\n";  
} 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}