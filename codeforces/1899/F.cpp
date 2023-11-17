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
	ll tt; cin >> tt;  while(tt--)
	solve();
	return 0;
}
void solve() {
	int n, q; cin >> n >> q;
	vector<int> v(q); for(auto &x : v) cin >> x;
	// int x = 1;
	for (int i = 1; i < n; i++) {
		cout << i << " " << i + 1 << "\n";
	}
	int in = 0; 
	for (int i = 0; i < q; i++) {
		if (v[i] == n-1) {
			cout << -1 << " " << -1 << " " << -1 << "\n";
			in = i + 1;
		} else {
			in = i; break;
		}
	}
	int last = n - 1;
	for (int i = in; i < q; i++) {
		cout << n << " " << last << " " << v[i] << "\n";
		last = v[i];
	}
}