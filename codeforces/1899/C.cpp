#include<bits/stdc++.h>
using namespace std;

#define ll    long long int
#define ff    first
#define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	ll tt; cin >> tt;  while(tt--)
	solve();
return 0;
}

//sol.
void solve(){
	int n; cin >> n;
	vector<int> v(n); for (auto &x : v) cin >> x;
	long long mx = v[0];
	long long sm = v[0];
	if (sm < 0) sm = 0;
	for (int i = 1; i < n; i++) {
		if ((v[i - 1] % 2 && v[i] % 2 == 0) || (v[i - 1] % 2 == 0 && v[i] % 2)) {
			sm += v[i];
			mx = max(mx, sm);
			if (sm < 0) {
				sm = 0;
			}
		} else {
			sm = v[i];
			mx = max(mx, sm);
			if (sm < 0) {
				sm = 0;
			}
		}
	}
	cout << mx << "\n";

}
