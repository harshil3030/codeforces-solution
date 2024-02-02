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
    int n,p,l,t; cin >> n >> p >> l >> t;
    int totalt = n/7 + ((n % 7 == 0) ? 0 : 1);
    int totall = n;


    int lo = 0, hi = 1e10;
    int ans = 0;
    while (lo <= hi) {
        int mid = (hi + lo)/2;
        if (mid >= n) {
            hi = mid - 1;
        }else {
            int workingdays = n - mid;
            int totaldays = workingdays*2;
            if ((min(totaldays, totalt) * t  + workingdays*l) >= p) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
            }
            // if (t > l) {
            //     cout << "here\n";

            //     // if (totalt <= totaldays) {
            //     //     int tot = (totalt*t) + (min((totaldays - totalt),totall) * l);
            //     //     cout << tot << " " << mid << "\n";
            //     //     if (tot >= p) {
            //     //         ans = mid;
            //     //         lo = mid + 1;
            //     //     }else {
            //     //         hi = mid - 1;
            //     //     }
            //     // }else {
            //     //     int tot = totaldays*t;
            //     //     if (tot >= p) {
            //     //         ans = mid;
            //     //         lo = mid + 1;
            //     //     }else {
            //     //         hi = mid - 1;
            //     //     }
            //     // }

            //     if ()
            // }else {
            //     if (totall <= totaldays) {
            //         int tot = (totall*l) + (min(totaldays - totall, totalt) * t);
            //         if (tot >= p) {
            //             lo = mid + 1;
            //             ans = mid;
            //         }else {
            //             hi = mid - 1;
            //         }
            //     } else {
            //         int tot = totaldays*l;
            //         if (tot >= p) {
            //             lo = mid + 1;
            //             ans = mid;
            //         }else {
            //             hi = mid - 1;
            //         }
            //     }
            // }
        }
    }
    cout << ans << "\n";
}
