#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (auto &x : v) cin >> x;

   bool okclock = true;
   bool okcounterclock = true;
   int ind = -1;
   for (int i = 0; i < n; i++) {
        if (v[i] == n) {
            ind = i;
            break;
        }
   } 

   for(int i = ind; i > 0; i--) {
       if (v[i] - 1 != v[i-1]) {
        okclock = false;
       }
   }

   for (int i = n-1; i > ind + 1; i--) {
        if (v[i] - 1 != v[i-1]) okclock = false;
   }

   for (int i = ind - 1; i > 0; i--) {
      if (v[i] != v[i-1] - 1) okcounterclock = false;
   }
   
   for (int i = n-1; i > ind; i--) {
      if (v[i] != v[i-1] - 1) okcounterclock = false;
   }

   if (okclock || okcounterclock) {
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