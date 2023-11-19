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
	// ll tt; cin >> tt;  while (tt--)
		solve();
	return 0;
}
void solve() {
	int n, m, k; cin >> n >> m >> k;
	char arr[n][m];
	int dots = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '.') dots += 1;
		}
	}
	if (k == 1) {
		cout << dots << "\n";
		return;
	}
	long long sm = 0;
	// int cnt = 0;
	vector<long long> cont;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.') {
				cnt++;
			}else {
				cont.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt) cont.push_back(cnt);
	}

	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == '.') {
				cnt++;
			}else {
				cont.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt) cont.push_back(cnt);
	}

	for (int i = 0; i < (int)cont.size(); i++) {
		if (cont[i] - k >= 0) {
			sm += cont[i] - k + 1;
		}
	}
	cout << sm << "\n";
}
