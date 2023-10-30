#include<bits/stdc++.h>
using namespace std;
#define ll    long long
#define lcm(a, b) (a * b) / __gcd(a, b)
#define ff first
#define ss second
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
ll tc = 0;
void solve();
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll tt; cin >> tt; while (tt--)
	solve();
	return 0;
}

//sol.
void solve() {
	ll n; cin >> n;
	vector<ll> v(n); vector<ll> b(n);
	for(auto &x : v) cin >> x;
	for(auto &x : b) cin >> x;
	sort(v.begin(), v.end());
	sort(b.begin(), b.end());
	ll sm1 = 0; ll sm2 = 0;
	for (int i = 0; i < n; i++) {
		sm1 += v[0] + b[i];
	}
	for (int i = 0; i < n; i++) {
		sm2 += v[i] + b[0];
	}
	cout << min(sm1 , sm2) << "\n";
}