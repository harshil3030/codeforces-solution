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
	long long n; cin >> n;
	vector <long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == cnt + 1) {
			cnt += 2;
		}else cnt+=1;
	}
	cout << cnt << "\n";
}
