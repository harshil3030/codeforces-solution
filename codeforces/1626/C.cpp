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
	int n;
	cin >> n;
	vector<int> k(n);
	for (auto &x : k) cin >> x;
	vector<int> h(n);
	for (auto &x : h) cin >> x;

	auto check = [&](int tar) -> bool {
		int need = 0;
		int mx = h[n-1];
		int last = k[n-1];
		for (int i = n-1; i > 0; i--) {
			if(last - k[i-1] < mx) {
				mx = max(mx,h[i-1]+(last - k[i-1]));
			} else {
				need += (mx*(mx+1))/2;
				mx = h[i-1];
				last = k[i-1];
			}
		}
		if(mx) {
			need += (mx*(mx+1))/2;
		} 
		if (need <= tar) {
			return true;
		}
		return false;
	};


	int ans = 1e18;
	int lo = 0, hi = 1e18;
	while (lo <= hi) {
		int mid = (hi - (hi - lo)/2);
		if(check(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}    
	cout << ans << "\n";
}
