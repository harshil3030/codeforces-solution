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
    int n,c,k; cin >> n >> c >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<int> pref(n + 1);
    pref[0] = 0;
    if (c == 0) {
        cout << "Infinity\n";
        return;
    }
    sort(v.rbegin(),v.rend());
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + v[i-1];
    int tot = pref[min(k,n)];
    if (c > k*v[0]) {
        cout << "Impossible\n";
        return;
    } else if (tot >= c) {
        cout << "Infinity\n";
        return;
    } else {
        int lo = 0; int hi = k-1;
        // int temp = k; 
        int ans = 1;
       

        while (lo <= hi) {
            int mid = (lo + hi)/2;
            int x = min(mid + 1,n);
            int temp = k;
            int sm = 0;
            while (temp > 0) {
                if (temp >= x) {
                    sm += pref[x];
                    // cout << sm << " " << "sm : " << "\n";
                    temp = temp - mid - 1;
                } else {
                    sm += pref[temp];
                    temp = 0;
                }
            }


            // cout << "here\n";
            // cout << mid << " " << sm << " " << hi << "\n";
            if (sm >= c) {
                lo = mid + 1;
                ans = mid;
            }else {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    } 

}
