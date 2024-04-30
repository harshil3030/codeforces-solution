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
	int n,k; cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v) cin >> x;

	
	auto check = [&](int tar) {
		int req = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] < tar) {
				req += (tar - v[i]);
			}
		}
		if (req > k) return false;
		return true;
	};
	int ans = 1;
	int lo = 1, hi = 1e12;
	while (lo <= hi) {
		int mid = (hi + lo)/2;
		if(check(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
		
	}  

	int elementPower = ans;

	int tot = ans * n;
	int remainK = k;
	for (int i = 0; i < n; i++) {
		if (v[i] < ans) {
			remainK -= (ans - v[i]);
		}
	}

	int totLength = ans * n;
	int remainFront = 0;
	int remainBack = 0;
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (v[i] > ans) {
			remainFront++;
			last = i;
		} else {
			break;
		}
	}
	for (int i = n-1; i > last; i--) {
		if (v[i] > ans) {
			remainBack++;
		}
	}

	int extra = remainK + remainFront + remainBack;
	cout << totLength + extra - (n - 1) << "\n";


}
