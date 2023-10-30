#include<bits/stdc++.h>
using namespace std;
#define ll    long long
#define lcm(a, b) (a * b) / __gcd(a, b)
#define ff first
#define ss second
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
ll tc = 0;
void solve();
int main() {
	fastIO;
	ll tt; cin >> tt; while (tt--)
	solve();
	return 0;
}

//sol.
void solve() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	map<char, ll> mp;
	for(int i = 0; i < n; i++) mp[s[i]] += 1;
	ll got = 0;
	for (auto &x : mp) {
		if (x.ss % 2) got++;
	}
	if (k >= got - 1) {
		cout << "YES\n"; return;
	} else cout << "NO\n";
}