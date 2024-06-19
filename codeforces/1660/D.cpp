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

    auto do_stuff = [&](int start, int end) -> pair<int, int> {
        int cnt_minus = 0;
        for(int i = start; i <= end; i++) {
            if(v[i] < 0) cnt_minus++;
        }
        int cnt2s = 0;
        int cnt2l = 0;
        int rets = start, rete = end;
        if (cnt_minus % 2) {
            for(int i = start; i <= end; i++) {
                if (v[i] == 2 || v[i] == -2) cnt2s++;
                if (v[i] < 0) {
                    rets = i+1;
                    break;
                }
            }

            for(int i = end; i >= start; i--) {
                if (v[i] == 2 || v[i] == -2) cnt2l++;
                if (v[i] < 0) {
                    rete = i-1;
                    break;
                }
            }

            if (cnt2s > cnt2l) {
                return {start, rete};
            } else {
                return {rets, end};
            }

        } else {
            return {start, end};
        }
    };

    auto map_through = [&](int start, int end)-> int {
        int cnt2 = 0;
        for(int i = start; i <= end; i++)
            if (v[i] == 2 || v[i] == -2) cnt2++;
        return cnt2;
    };

    int zero = 0;
    for(auto &x : v) if (x == 0) zero++;

    if (zero) {
         int last = 0;
         while(last < n && v[last] == 0) last++;
         vector<pair<int, int>> ps;
         for(int i = last; i < n; i++) {
             if (v[i] == 0) {
                 if (last <= i-1)
                 ps.push_back(do_stuff(last, i-1));
                 last = i+1;
             }
         }

         if (last <= n-1) {
             ps.push_back(do_stuff(last, n-1));
         }

         if (ps.empty()) {
             cout << n << " " << 0 << "\n";
             return;
         }

         pair<int, int> final = ps[0];
         int mx = map_through(ps[0].first, ps[0].second);
         for(int i = 1; i < ps.size(); i++) {
             if (ps[i].first <= ps[i].second) {
                 int curr = map_through(ps[i].first, ps[i].second);
                 if (curr > mx) {
                     mx = curr;
                     final = ps[i];
                 }
             }
         }
        if (final.second < final.first) {
            cout << n << " " << 0 << "\n";
            return;
        }
         cout << final.first << " " << n-final.second-1 << "\n";
    } else {
        pair<int, int> p = do_stuff(0, n-1);
        if (p.first > p.second) {
            cout << n << " " << 0 << "\n";
            return;
        }
        cout << p.first << " " << n-p.second-1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}