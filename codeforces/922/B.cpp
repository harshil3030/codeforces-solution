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
// 	ll tt; cin >> tt;  while (tt--)
		solve();
	return 0;
}
void solve() {
	long long n; cin >> n;
	set<vector<int>> st;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int k = i ^ j;
				vector<int> cont;
				if (i + j > k && (i ^ j ^ k == 0) && k <= n && k >= 0 && k >= j) {
					int xorsm = i ^ j ^ k;
					if (xorsm == 0) {
						// cout << "here\n";
						cont.push_back(i); cont.push_back(j); cont.push_back(k);
						sort(cont.begin(), cont.end());
						st.insert(cont);
					}
				}
		}
	}
	cout << st.size() << "\n";
}
