#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;


    auto checklo = [&](int x) -> int {
        int low = 0; int high = n;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if ((n * n <= (mid * mid + x * x)  &&  (mid * mid + x * x) < (n + 1) * (n + 1)) || (mid*mid + x*x >= (n+1)*(n+1))) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    };


    auto checkhi = [&](int x) -> int {
        int low = 0; int high = n;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if ((n * n <= (mid * mid + x * x)  &&  (mid * mid + x * x) < (n + 1) * (n + 1)) || (mid*mid + x*x < (n)*(n))) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    };





    int cnt = 0;
    for (int x = 0; x <= n; x++) {
        int lo = checklo(x);
        if(lo <= -1) continue;
        int hi = checkhi(x);
        if(hi <= -1) continue;
     
        // cout << x << " " << hi << " " << lo << " " << "\n";
        cnt += (hi-lo+1);
        // if (((((hi*hi + x*x) >= n*n) && ((hi*hi + x*x) < ((n+1)*(n+1)))) && (lo*lo + x*x) >= n*n)  && (lo*lo + x*x) < ((n+1)*(n+1))) {    
        //     cnt += 3*((hi*(hi+1))/2);
        //     cnt -= 3*((lo*(lo+1))/2);
        // }
    }   
    cout << 4*cnt-4 << "\n";
}
