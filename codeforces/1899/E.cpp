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
	long long moves = 0;
	int n; cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int cnt = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] <= v[i + 1]) cnt++;
		else break;
	}
	moves = n - cnt;
	int mn = *min_element(v.begin(), v.end());
	int in = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == mn) { 
			in = i; break; }
	}
	int flg = 0;
	for (int i = in + 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			flg = 1; break;
		}
	}
	if (flg == 1) {
		cout << -1 << "\n";
	}else {
		cout << moves << "\n";
	}

}