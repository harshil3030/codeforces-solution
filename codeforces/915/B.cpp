#include<bits/stdc++.h>
using namespace std;

#define ll    long long int
#define ff    first
#define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// ll tt; cin >> tt;  while(tt--)
	solve();
	return 0;
}
void solve() {
	long long n, pos, l, r; cin >> n >> pos >> l >> r;
	long long sm = 0; int flg = 0;
	// if (l <= pos && pos <= r) {
	// 	if (l > 1) { sm += pos - l + 1; flg++; }
	// 	if (r < n) { sm += r - pos + 1; flg++; }
	// 	if (flg == 2) sm +=  min(pos - l, n - pos);
	// 	cout << sm << "\n";
	// 	return;
	// } else if (pos < l) {
	// 	if (r == n) {
	// 		cout << 1 << "\n";
	// 		return;
	// 		// sm += max(1 * 1ll, l - pos - 1);
	// 	}else {
	// 		sm += r - l + 2;
	// 		// sm += r - pos + 1;
	// 	}
	// 	cout << sm << "\n";
	// 	// cout << 1 << "\n";
	// } else {
	// 	if (l == 1) {
	// 		cout << 1 << "\n";
	// 		return;
	// 	// 	sm += max(1 * 1ll, pos - r - 1);
	// 	} else {
	// 		sm += r - l + 2;
	// 		// sm += pos - l + 1;
	// 	}
	// 	cout << sm << "\n";
	// 	// cout << 1 << "\n";

	if (l == 1 && r == n) {
		cout << 0 << "\n"; return;
	}
	if (pos >= l && pos <= r) {
		if (l > 1) { sm += pos - l + 1; flg++; }
		if (r < n) { sm += r - pos + 1; flg++; }
		if (flg == 2) sm +=  min(pos - l, r - pos);
		cout << sm << "\n";	
	} else if (pos < l) {
		if (r == n) {
			cout << l - pos + 1 << "\n";
		}else {
			cout << r - pos + 2 << "\n";
		}
	} else {
		if (l == 1) {
			cout << pos - r + 1 << "\n";
		} else {
			cout << pos - l + 2 << "\n";
		}
	}
}