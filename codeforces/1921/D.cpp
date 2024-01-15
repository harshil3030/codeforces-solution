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
    int n,m; cin >> n >> m;
    vector<int> v(n);
    vector<int> a(m);
    for (auto &x:  v) cin >> x;
    for (auto &x : a) cin >> x;
    int res1 = 0, res2 = 0;    
	int res3 = 0, res4 = 0;
	sort(v.begin(), v.end());
	sort(a.begin(), a.end()); 

	int i = 0, j = n-1; int k = 0, l = m-1;
	while (i <= j && k <= l) {
		int ff = abs(v[i] - a[l]);
		int ss = abs(v[j] - a[k]);
		if (ff > ss) {
			res1 += ff;
			l--; i++;
		}else {
			res1 += ss;
			k++; j--;
		}
	}  

	 i = 0, j = n-1; k = 0, l = m-1;
	while (i <= j && k <= l) {
		int ff = abs(v[i] - a[l]);
		int ss = abs(v[j] - a[k]);
		if (ff >= ss) {
			res2 += ff;
			l--; i++;
		}else {
			res2 += ss;
			k++; j--;
		}
	}  

	cout << max(res1,res2) << "\n";
}
