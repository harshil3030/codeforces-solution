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
	long long n, k; cin >> n >> k;
	if (k == 1) {
		cout << n << "\n";
		return;
	}
	long long cnt = 0;
	long long temp = n;
	while (temp > 0) {
		temp /= 2; cnt++;
	}
	long long sm = 0;
	long long mul = 1;
	while (cnt--) {
		sm += mul;
		mul *= 2;
	}
	cout << sm << "\n"; 	
}