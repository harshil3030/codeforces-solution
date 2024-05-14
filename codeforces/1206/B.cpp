#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int need = 0;
	
	int mone = 0;
	bool isZero = false;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) mone++;
		if (v[i] == 0) isZero = true;
	}
	if (mone % 2 == 0 || isZero) {
		for(int i = 0; i < n; i++) {
			need += abs(abs(v[i]) - 1);
		}
		cout << need << "\n";
		return;
	} else {
		for(int i = 0; i < n; i++) {
			need += abs(abs(v[i]) - 1);
		}
		need += 2;
		cout << need << "\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
