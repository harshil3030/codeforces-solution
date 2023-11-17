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
	long long n; cin >> n;
	vector<long long> v(n); 
	for (auto &x : v) cin >> x;
	long long diff = 0;
	
	if (n == 1) {
		cout << 0 << "\n";
		return;
	}

	long long pref[n + 1];
	pref[0] = 0;
	for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];

	// long long diff = 0;
	long long sm = 0;
	for (auto &x : v) sm += x;
	for (long long i = 1; i <= n; i++) {
		long long mn = sm; long long mx = 0; 
		if (n % i == 0) {
			for (long long j = i; j <= n ;j += i) {
				if (pref[j] - pref[j - i] < mn) {
					mn = pref[j] - pref[j - i];
				} 
				if (pref[j] - pref[j - i] > mx) {
					mx = pref[j] - pref[j - i];
				}
			}
			diff = max(diff, mx - mn);
		}
	}
	long long t = 0;
	cout << max(diff, t) << "\n";
}