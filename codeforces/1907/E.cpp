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
    int ind[10];
    
    auto digsm = [&](int n) -> int {
      int tmp = n;
      int ans = 0;
      while (tmp > 0) {
          ans += tmp % 10;
          tmp /= 10;
      }  
      return ans;
    };
    
  for (int ele = 0; ele < 10; ele++) {
      int tot = 0;  
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                     if (digsm(i) + digsm(j) + digsm(k) == digsm(ele) && 
                         i + j + k == ele) {
                          tot+=1;           
                         }            
                }
            }
        }
        ind[ele] = tot;
    }
       
    int final = 1;
    while (n > 0) {
        final *= ind[(n % 10)];
        n/=10;
    }   
    cout << final << "\n";
}
