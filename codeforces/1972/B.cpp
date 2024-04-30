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
	int n; cin >> n;
	string s; cin >> s;
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'D') {
			d++;
		} 
	}   
	if (d % 2) n -= 1;
	if (n % 2 == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
