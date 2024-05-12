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
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int sm = 0;
	for (int i = 0; i < n; i++) {
		sm += v[i];
	}   

	int ext = -1;
	map<int, int> vis;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int ind;
			cin >> ind;
			int val;
			cin >> val;
			if (ext != -1 && vis[ind-1] == 0) {
				vis[ind-1] = 1;
				sm -= ext;
			} else {
				sm -= v[ind - 1];
			}
			sm += val;
			cout << sm << "\n";
			v[ind - 1] = val;
		} else {
			int val;
			cin >> val;
			cout << n * val << "\n";
			sm = n*val;
			ext = val;
			vis.clear();
		}
	}
}
