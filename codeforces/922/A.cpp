#include<bits/stdc++.h>
using namespace std;

#define ll    long long int
// #define ff    first
// #define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
// 	ll tt; cin >> tt;  while (tt--)
		solve();
	return 0;
}
void solve() {
	long long x, y; cin >> x >> y;
	if (x == 0) {
		if (y == 1) {
			cout << "YES\n";
		}else cout << "NO\n";
	}
	else if (y == 1) {
		if (x >= 1) {
			cout << "NO\n";
		}else {
			cout << "NO\n";
		}
	} else if (x % 2 == 0 && y % 2 && y >= 1 && y - x <= 1) {
		cout << "YES\n";
	} else if (x % 2 && y % 2 == 0 && y >= 1 && x >= 1 && y - x <= 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
