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
	for (auto &x : v) cin >> x;
	map<long long, long long> mp;
	long long mx = 1;

	for (auto &x : v) mp[x]++;
	vector<pair<long long, long long>> vp(n);
	for (int i = 0; i < n; i++) {
		vp[i].first = v[i];
		vp[i].second = mp[v[i]];
	}
	auto comp = [&](pair<long long,long long> &p1, pair <long long, long long> &p2) {
		return p1.first < p2.first;
	};
	sort(vp.begin(), vp.end(), comp); mp.clear();
	mp[v[0]]++;
	long long cnt = 0;
	cnt = vp[0].second;
	for (int i = 1; i < n; i++) {
		if (vp[i - 1].first + 1 < vp[i].first) {
			cnt += vp[i].second;
		}else if (vp[i].second > vp[i - 1].second) {
			cnt += vp[i].second - vp[i - 1].second;
		}
	}
	cout << cnt << "\n";
}
