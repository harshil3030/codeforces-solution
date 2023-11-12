#include<bits/stdc++.h>
using namespace std;

#define ll    long long
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
	// ll tt; cin >> tt;  while(tt--)
	solve();
return 0;
}

//sol.
void solve(){
	int n; cin >> n;
	set<ll> st[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			ll x; cin >> x; st[i].insert(x);
		}
	}	 

	int mx = 0; int last = 0;
	for (int j = 1; j <= 999; j++) {
		int temp = j; map<ll, ll> mp2; int size = 0;
		while (temp > 0) {
			mp2[temp % 10]++; temp /= 10; size++;
		}
		int mx2 = 0;
		for (int i = 0; i < n; i++) {
			 int cnt = 0;
			 int flg[n]; for (auto &x : flg) x = 1;
			for (auto &x : mp2) {
				for (int l = 0; l < x.second; l++) { 
					if (st[i % n].find(x.first) != st[i % n].end() && flg[i % n]) {
						flg[i % n] = 0; cnt++;
					} else if (st[(i + 1) % n].find(x.first) != st[(i + 1) % n].end() && flg[(i + 1) % n]) {
						flg[(i + 1) % n] = 0; cnt++;
					} else if(st[(i + 2) % n].find(x.first) != st[(i + 2) % n].end() && flg[(i + 2) % n]) {
						flg[(i + 2) % n] = 0; cnt++;
					} 
				}
			} mx2 = max(mx2, cnt);
		}
		if (size != mx2) {
			cout << last << "\n"; return;
		}
		last = j;
	}
	cout << last << "\n";
}

