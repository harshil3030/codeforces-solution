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
    int n,m;
    cin >> n >> m;
    string ans1 = "", ans2 = "";
    int tot = m;
    if(m == 0 && n == 1) {
        cout << 0 << " " << 0 << "\n";
        return;
    } 
    if ((m == 0 && n > 1) || n*9 < m) {
        cout << -1 << " " << -1 << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        int mn = min(9ll, tot);
        ans1 += '0' + mn;
        tot -= mn;
    }
    ans2 = ans1;
    reverse(ans2.begin(), ans2.end());
    if (ans2[0] == '0') {
        ans2[0] = '1';
        for(int i = 1; i < n; i++) {
            if (ans2[i] != '0') {
                char curr = ans2[i];
                int inInt = curr-'0';
                ans2[i] = ((inInt-1) + '0');
                break;
            }
        }
    }

    cout << ans2 << " " << ans1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}