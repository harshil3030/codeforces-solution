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
    int sm = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    int cnt = 0;
    vector<int> st;
    while (sm != mx) {
        if (sm % 2 == 0) {
            st.push_back(0);
            sm/=2;
            mx/=2;
        }else {
            st.push_back(1);
            sm = (sm+1)/2;
            mx = (mx+1)/2;
        }
        cnt++;
    }

    if (cnt <= n) {
        cout << cnt << "\n";
        for(auto &x : st) cout << x << " ";
        cout << "\n"; 
        return;
    }
    cout << cnt << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}