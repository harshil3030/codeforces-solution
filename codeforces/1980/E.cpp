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
  vector<vector<int>> a(n, vector<int> (m));
  for(auto &x : a) {
  	for(auto &y : x) cin >> y;
  } 
	
	vector<vector<int>> b(n, vector<int> (m));
	for(auto &x : b) {
		for(auto &y : x) cin >> y;
	} 
	
	map<vector<int>, int> col;
	map<vector<int>, int> row;
	vector<vector<int>> tmp = a;
	vector<vector<int>> tmp2 = b;
	for(int i = 0; i < n ;i++) {
		sort(tmp[i].begin(), tmp[i].end());
		sort(tmp2[i].begin(), tmp2[i].end());
		row[tmp[i]]++;
	}
	bool ok = false;
	for(int i = 0; i < n; i++) {
		if (row[tmp2[i]] == 0) {
			cout << "NO\n";
			return;
		}
		row[tmp2[i]]--;
	}
	vector<vector<int>> tmp3 (m, vector<int> (n));
	vector<vector<int>> tmp4 (m, vector<int> (n));
	for(int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tmp3[i][j] = a[j][i];
			tmp4[i][j] = b[j][i];
		}
	}

	for (int i = 0; i < m; i++) {
		sort(tmp3[i].begin(), tmp3[i].end());
		sort(tmp4[i].begin(), tmp4[i].end());
		col[tmp3[i]]++;
	}

	for(int i = 0; i < m; i++) {
		if (col[tmp4[i]] == 0) {
			cout << "NO\n";
			return;
		}
		col[tmp4[i]]--;
	}

	cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}