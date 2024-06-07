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
 	int n,m,k;
 	cin >> n >> m >> k;
 	vector<pair<int, pair<int, int>>> vp(k);
 	map<pair<int, int>, int> ind;
 	map<int, vector<int>> mp;
 	for (int i = 0; i < k; i++) {
 		vp[i].first = i;
 		cin >> vp[i].second.first >> vp[i].second.second;
 		ind[{vp[i].second.first, vp[i].second.second}] = i;
 		mp[vp[i].second.first].push_back(vp[i].second.second);  
 	} 

 	int ext = 0;
 	int sm = 0;
 	vector<int> ans(k, 0);
 	int mn = 1e12;
 	vector<pair<int,int>> row;
 	while (!mp.empty()) {
 		auto it = mp.rbegin();
 		pair<int, vector<int>> p = *it;
 		mp.erase((--mp.end()));

 		int currmn = *min_element(p.second.begin(), p.second.end());
 		if (currmn < mn) {
 			ans[ind[{p.first, currmn}]] = 1;
 			mn = currmn;
 		}
 		row.push_back({p.first, mn});
	}

	int till = n;
	int cmn = m;
	for (int i = 0; i < row.size(); i++) {
		int r = row[i].first;
		sm += (till - r)*cmn;
		cmn = row[i].second-1;
		till = r;
	}
	sm += (till)*cmn;

	cout << max(1ll,sm) << "\n";
	for (auto &x : ans) {
		cout <<  x << " ";
	} cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}