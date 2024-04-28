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
	int lastEven = (n % 2) ? n - 1 : n;
	int lastOdd = (n % 2) ? n : n - 1;
	if (n == 1) {
		cout << n << "\n";
		return;
	} else if (n == 2 || n == 3) {
		cout << -1 << "\n";
		return;
	}
	if (lastOdd > lastEven) {
		for (int i = 1; i <= lastOdd; i += 2) {
			cout << i << " ";
		} 
		cout << lastEven - 2 << " ";
		cout << lastEven << " ";
		for (int i = lastEven - 4; i > 0; i -= 2) {
			cout << i << " ";
		} cout << "\n";
	} else {
		for (int i = 2; i <= lastEven; i += 2) {
			cout << i << " ";
		}
		cout << lastOdd - 2 << " ";
		cout << lastOdd << " ";
		for (int i = lastOdd - 4; i > 0; i -= 2) {
			cout << i << " ";
		} cout << "\n";
	}   
}
