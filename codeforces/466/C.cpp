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
    if (n <= 2) {
        cout << 0 << "\n";
        return;
    }
    vector<int> pref(n + 1), suff(n + 1);
    pref[0] = 0, suff[n] = 0;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i-1];
    }

    for(int i =n-1; i >= 0; i--) {
        suff[i] = suff[i+1] + v[i];
    }
    map<int, int> freq_pref;
    vector<int> ind;
    for(int i = 1; i <= n-1; i++) {
        if (pref[i] == 2*suff[i]) {
            freq_pref[pref[i]]++;
            ind.push_back(i);
        }
    }
    int ans = 0; int k = 0;
    for(int i = 1; i <= n-2; i++) {
        if (ind.size() > 0 && k < ind.size() && i == ind[k]) {
            k++;
            freq_pref[pref[i]]--;
        }
        int need = 2*pref[i];
        int get = freq_pref[need];
        if (get > 0) ans += get;
    }
    cout << ans << "\n";




//
//    vector<int> zero_seg(n, 0);
//    int curr_zero = 0;
//    for(int i = 0; i < n; i++) {
//        if (v[i] == 0) {
//            curr_zero++;
//            zero_seg[i] = curr_zero;
//        }  else {
//            curr_zero = 0;
//        }
//    }
//    bool ok = false;
//    int taken = -1;
//    for(int i = n-1; i >= 0; i--) {
//        if (v[i] == 0) {
//            if (!ok) {
//                ok = true;
//                taken = zero_seg[i];
//            }
//            zero_seg[i] = taken;
//        }else {
//            ok = false;
//        }
//    }
//
//    auto bin_search = [&](int tar, int find_sum) -> int {
//      int lo = tar;
//      int hi = n-1;
//      int ans = n;
//      while (lo <= hi) {
//          int mid = (lo + hi) >> 1;
//          int sum_mid_seg = pref[mid + 1] - pref[tar];
//          int last_seg_sum = suff[mid + 1];
//          if (sum_mid_seg == last_seg_sum && sum_mid_seg == find_sum) {
//              ans = mid;
//          }
//
//          if (sum_mid_seg <= find_sum) {
//              lo = mid + 1;
//          } else {
//              hi = mid - 1;
//          }
//      }
//      return ans;
//    };

//    int ans = 0;
//    for(int i = 0; i < n; i++) {
//        int curr_sum = pref[i+1];
//        int ind = bin_search(i+1, 2*curr_sum);
//        if (ind >= n) {
//            continue;
//        }
//        cout << ind << "\n";
//        int zeros = min(ind - i, zero_seg[ind]);
//        if (!zeros) {
//            if (ind == n-1) continue;
//            ans += 1;
//        } else {
//            ans += zeros;
//        }
//    }
//    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}