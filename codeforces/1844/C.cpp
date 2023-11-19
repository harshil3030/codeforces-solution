#include<bits/stdc++.h>
using namespace std;
long long t = 0;
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
	ll tt; cin >> tt;  while (tt--)
		solve();
	return 0;
}
void solve() {
	// t++;
	long long n; cin >> n;
	vector<long long> v(n); for(auto &x : v) cin >> x;
	if (n == 1) { cout << v[0] << "\n"; return;}
	long long poss = *max_element(v.begin(), v.end());
	long long flg = 0;
	long long sm1 = 0, sm2 = 0;
	int in1 = 0, in2 = n - 1;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) in1 = i;
		else {in1 = i; break;}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] < 0) in2 = i;
		else {in2 = i; break;}
	}
	if (in2 <= in1) {
		cout << poss << "\n";
		return;
	}
	for (int i = in1; i <= in2; i += 2) {
		sm1 += max(v[i], (long long)0);
	}
	for (int i = in1 + 1; i <= in2; i += 2) {
		sm2 += max(v[i], (long long)0);
	}
	cout << max(max(sm1, sm2), poss) << "\n";
}
