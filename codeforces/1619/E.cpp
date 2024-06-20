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
    map<int, int> mp;
    for(auto &x : v) {
        mp[x] += 1;
    }
    int curr = 0;
    int sm = 0;
    int tot = 0;
    int till = n+1;
    vector<pair<int, int>> lasts;
    vector<int> ans(n + 1, -1);
    for(int i = 0; i <= n; i++) {
        if (tot < (i)) {
            till = i-1;
            break;
        }
        if (mp.count(i)) {
            ans[i] = curr + mp[i];
        }else {
            ans[i] = curr;

            if (lasts.size() == 0) {
                till = i;
                break;
            }
            pair<int, int> last_one = lasts.back();
            if (last_one.first > 1) {
                curr += (i - last_one.second);
                lasts.back().first--;
            } else {
                lasts.pop_back();
                curr += (i - last_one.second);
            }
        }
        tot += mp[i];
        if (mp[i] > 1) {
            lasts.push_back({mp[i]-1, i});
        }
    }
    if (till == n + 1) till = n;
    for(int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}