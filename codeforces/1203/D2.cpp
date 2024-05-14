#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
	string s,t;
	cin >> s >> t;
	int n = s.length();
	int k = t.length();
	int mx = 0;
    int pref[k] = {0};
    int suff[k] = {0};
    int currInd = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[currInd]) {
            pref[currInd++] = i;
            if (currInd == k) break;
        }
    }
    currInd = k-1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == t[currInd]) {
            suff[currInd--] = i;
            if (currInd == -1) break;
        }
    }

    int ans = max(suff[0], n-1-pref[k-1]);
    for(int i = 0; i + 1 < k; i++) {
        ans = max(ans, suff[i+1] - pref[i] - 1);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}