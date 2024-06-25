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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> seg;
    vector<char> chars;
    string ans;
    int cnt = 1;
    for(int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            cnt++;
        } else {
            seg.push_back(cnt);
            cnt = 1;
            chars.push_back(s[i]);
        }
    }
    if (cnt >= 2) {
        seg.push_back(cnt);
        chars.push_back(s[n-1]);
    } else {
        seg.push_back(1);
        chars.push_back(s[n-1]);
    }

    bool last_ok = true;
//    for(auto &x : seg) cout << x << " "; cout << "\n";
//    for(auto &x : chars) cout << x << " ";
    for(int i = 0; i < seg.size(); i++) {
        if (seg[i] >= 2) {
            if (!last_ok) {
                seg[i] = 1;
                ans += chars[i];
                last_ok = true;
            } else {
                ans += chars[i];
                ans += chars[i];
                last_ok = false;
            }
        } else {
            ans += chars[i];
            last_ok = true;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}