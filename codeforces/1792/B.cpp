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
	long long a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	long long sm = 0;
	if (a1 + a2 + a3 + a4 == 1) {
		cout << 1 << "\n";
		return;
	}
	sm = a1;
	if (a1 == 0) {
		cout << 1 << "\n";
		return;
	}
	long long steps = a1 + 1;
	sm += min(a2, a3) * 2;
	long long rest = max(a2, a3);
	rest -= min(a2, a3);
	if (rest >= steps) {
		sm += steps;
		cout << sm << "\n";
		return;
	}else {
		steps -= rest;
		sm += rest;
	}
	if (!a4){
	 cout << sm << "\n";
	 return;
	}
	
	cout << sm + min(steps, a4) << "\n";
}
