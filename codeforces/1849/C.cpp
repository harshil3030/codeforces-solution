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
 string s;
 cin >> s;
 int pref0[n];
 int suff1[n];
 int curr = -1;
 for(int i = 0; i < n; i++) {
 	if (s[i] == '0') curr = i;
 	pref0[i] = curr;
 }  
 curr = n + 1;
 for(int i = n-1; i>=0; i--) {
 	if (s[i] == '1') curr = i;
 	suff1[i] = curr;
 }

 set<pair<int, int>> st;
 while (m--) {
 	int l, r;
 	cin >> l >> r;
 	l--, r--;
 	int One = suff1[l];
 	int Zero = pref0[r];

 	if (Zero < One || Zero < l || One > r || l == r) {
 		st.insert({0, 0});
 	} else {
 		st.insert({One, Zero});
 	}
 }
 cout << st.size() << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}