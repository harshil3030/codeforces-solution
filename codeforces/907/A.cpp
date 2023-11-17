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
	int b1, b2, b3, m; cin >> b1 >> b2 >> b3 >> m;
	int c1, c2, c3;
	int small = min(b3, m);
	small *= 2;
	c3 = small;
	if (m > c3 || b3 > c3 || m*2 < c3 || b3*2 < c3) {
		cout << -1 << "\n";
		return;
	}
	c1 = b1 * 2;
	c2 = b2 * 2;
	if (m > c1 || m > c2) {
		cout << -1 << "\n";
		return;
	}
	if (2 * m >= c1 || 2 * m >= c2) {
		cout << -1 << "\n";
		return;
	}
	if (c1 < c3 || c2 < c3) {
		cout << -1 << "\n";
		return;
	}
	cout << c1 << " " << c2 << " " << c3 << "\n";
}