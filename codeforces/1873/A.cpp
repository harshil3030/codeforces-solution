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
	string s;
	cin >> s;
	int cnt = 0;
	// for (int i = 0; i < s.length(); i++) {
		if (s[0] == 'a') cnt++;
		if (s[1] == 'b') cnt++;
		if (s[2] == 'c') cnt++;
	// }cout <<
		// cout << cnt << "\n";
		if (cnt >= 1) {cout << "YES\n"; return;}
		cout << "NO\n";
}
