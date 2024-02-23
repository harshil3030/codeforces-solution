#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
       int n; cin >> n;
       vector<int> v(n);
       int one = 0;
       for (auto &x : v) cin >> x;
       
       
       int ind = n-1;
       int ind2 = 0;
       int flg = 0;
       for (int i= 0; i < n; i++) {
           if (v[i] == 1) {
               flg = 1;
           }
           if (v[i] == 0 && flg) {
               ind = i;
               break;
           }
       }
       
       flg =  0;
       for (int i  = n-1; i>= 0; i--) {
           if (v[i] == 1) {
               flg = 1;
           }
           if (v[i] == 0 && flg) {
               ind2 = i;
               break;
           }
       }
       
       int moves = 0;
       for (int i = ind; i <= ind2; i++) {
           if (v[i] == 0) moves++;
       }
    cout << moves << "\n";
}

