#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){

// ----------------- IO & IO Display Settings -----------------------//
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
// ----------------- IO & IO Display Settings -----------------------//

long long tt; cin >> tt;
while(tt--) solve();
return 0;
}

void solve(){
	//write down for each test case
		unsigned long long n, w;
		cin >> n >> w;

		vector <unsigned long long> v(n); for(auto &x : v) cin >> x;
		long long mx = *max_element(v.begin(), v.end());
		unsigned long long s = 1;
		unsigned long long e = mx + w;
		if (n == 1) {cout << w + v[0] << "\n"; return; }
		unsigned long long ans = 1;
		while (s <= e) {
			unsigned long long mid = s + (e - s)/2;
			unsigned long long get = 0;
			for (int i = 0; i < n; i++) {
				if (v[i] < mid) get += mid - v[i];
			}
			if (get <= w) {
				ans = mid;
				s = mid + 1;
			}else e = mid - 1;
		}
		unsigned long long comp = 1;
		cout << max(ans,comp) << '\n';
}
