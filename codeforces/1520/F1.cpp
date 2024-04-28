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
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
	int n,t,k; cin >> n >> t;
	cin >> k;
	int lo = 1, hi = n;
	// while (hi - lo > 1) {
	// 	int mid = hi - (hi - lo)/2;
	// 	cout << "?" << " " << 1 << " " << mid << endl;
	// 	int q; cin >> q;
		
	// 	int zeros = mid - q;
	// 	if (zeros >= k) {
	// 		hi = mid;
	// 	} else {
	// 		lo = mid + 1;
	// 	}
	// }
	while (lo < hi) {
		int mid = (lo+hi) >> 1;
		cout << "?" << " " << 1 << " " << mid << endl;
		int q; cin >> q;
		int zeros = mid - q;
		if (zeros >= k) {
			hi = mid;
		}else {
			lo = mid + 1;
		}
	}
	cout << "!" << " " << lo << endl;
}
