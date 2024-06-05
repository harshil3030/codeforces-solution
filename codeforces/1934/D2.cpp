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
 int n;
 cin >> n;
 int noofbit = 0;
 for(int i = 0; i <= 63; i++) {
 	if ((1ll << i) & n) noofbit++;
 }  

 int p1 = -1, p2 = -1;
 if (noofbit % 2 == 0) {
 	cout << "first" << endl;
 } else {
 	cout << "second" << endl;
 	cin >> p1 >> p2;
 }


 while (p1 != 0 && p2 != 0) {
 	if (p1 == -1 && p2 == -1) {
 		int clz = __builtin_clzll(n);
 		int fbit = 63 - clz;
 		int curr = (1ll << fbit);
 		int seccurr = curr ^ n;
 		cout << curr << " " << seccurr << endl;
 	} else{
	 	int bitp1 = 0;
	 	int bitp2 = 0;
	 	for (int i = 0; i <= 63; i++) {
	 		if ((1ll << i) & p1) bitp1++;
	 	}
	 	if (bitp1 % 2 == 0) {
	 		int clz = __builtin_clzll(p1);
	 		int fbit = 63 - clz;
	 		int curr = (1ll << fbit);
	 		int seccurr = curr ^ p1;
	 		cout << curr << " " << seccurr << endl;
	 	} else {
	 		int clz =__builtin_clzll(p2);
	 		int fbit = 63 - clz;
	 		int curr = (1ll << fbit);
	 		int seccurr = curr ^ p2;
	 		cout << curr << " " << seccurr << endl;
	 	}
 	}
 	cin >> p1 >> p2;
 }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}