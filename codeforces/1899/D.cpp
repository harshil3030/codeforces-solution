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
	int n; cin >> n;
	long long sm = 0;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 1) {
			v[i] = 2;
		}
	}
	map <long long, long long> mp;
	for (int i = 0; i < n; i++) {
		mp[v[i]] += 1;
	}

	for(auto &x : mp) {
		if (x.second > 1) {
			long long y = x.second - 1;
			sm += (y * (y + 1))/2;
		}
	}
	cout << sm << "\n";
}