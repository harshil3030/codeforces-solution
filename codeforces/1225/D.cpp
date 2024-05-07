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
    // int tt = 1; cin >> tt; while /(tt--)  
    solve();
    return 0;
}

void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	map<map<int, int>, int> req;
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		map<int, int> val;
		int ele = v[i];
		for (int j = 2; j*j <= ele; j++) {
			while(ele % j == 0) {
				ele/=j;
				val[j]++;
				val[j] %= m;
			}
		}
		if (ele > 1) {
			val[ele]++;
			val[ele] %= m;
		}

		map<int, int> need;
		map<int, int> final;
		bool ok = true;
		for (auto &x : val) {
			if (x.second > 0) {
				ok = false;
				final[x.first] = x.second;
				need[x.first] = m-x.second;
			}
		}
		ans += req[need];
		req[final]++;
	} 

	cout << ans << "\n";

}
