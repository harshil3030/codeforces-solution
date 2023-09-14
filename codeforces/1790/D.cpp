#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	set<int> st;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
		st.insert(v[i]);
		st.insert(v[i] + 1);
	}
	int last = 0;
	int cnt = 0;	
	for (auto x : st) {
		int freq = mp[x];
		cnt += max(0, freq - last);
		last = freq;
	}
	cout << cnt << "\n";
};
int main(){

// ----------------- IO & IO Display Settings -----------------------//
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
// ----------------- IO & IO Display Settings -----------------------//

int tt; cin >> tt;
while(tt--) solve();
return 0;
}

