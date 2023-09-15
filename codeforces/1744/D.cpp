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
	long long n;
	cin >> n;
	vector <long long> v(n);
	long long cnt = 0;
	for (auto &x : v) cin >> x;
	for (int i = 0; i < n; i++) {
		long long temp = v[i];
		while (temp % 2 == 0) {
			cnt++; temp/=2;
		} 
	}
	if (cnt >= n) {
		cout << 0 << "\n"; return;
	}long long op = 0;
	long long mul = 0;
	vector <long long> add;
	for (int i = n; i > 0; i--) {
		mul = 0;
		if (i % 2 == 0) {
			long long temp = i;
			while (temp % 2 == 0) {
				temp/=2; mul++;
			}add.push_back(mul);
		}
	}
	sort(add.rbegin(), add.rend());
	for (int i = 0; i < add.size(); i++) {
		cnt += add[i]; op++;
		if (cnt >= n) {
			cout << op << "\n"; return;
		}
	}cout << -1 << "\n";
}
