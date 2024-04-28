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
	auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		return p1.first < p2.first;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
	pq.push({n, 0});
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		pair<int, int> curr = pq.top();
		pq.pop();
		int len = curr.first;
		int start = curr.second;
		int end = curr.second + curr.first - 1;
		int mid = (start + end) >> 1;
		ans[mid] = (i + 1);
		if (len % 2) {
			pq.push({len/2, start});
			pq.push({len/2, mid + 1});
		} else {
			pq.push({len/2-1, start});
			pq.push({len/2, mid + 1});
		}
	}   
	for(auto &x : ans) cout << x << " ";
		cout << "\n";
}
