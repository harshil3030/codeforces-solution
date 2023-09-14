#include<bits/stdc++.h>
using namespace std;
void solve();
int searchLeft(vector<pair<long long,long long>>, int, int, int);
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
	long long n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> vp(n);
	for (int i = 0; i < n; i++) cin >> vp[i].first;
	for (int i = 0; i < n; i++) cin >> vp[i].second;
	sort(vp.begin(), vp.end());
	long long mn = vp[n - 1].second;
	for (int i = n - 1; i >= 0; i--) {
		mn = min(mn, vp[i].second);
		vp[i].second = mn;
	}
	vector<long long> v(n);
	for (int i = 0; i < n; i++) v[i] = vp[i].first;
	int temp = 0;
	while (k > 0) {
		auto it = upper_bound(v.begin(), v.end(), k + temp);
		if (it != v.end()) {
			int ind = it - v.begin();
			temp += k;
			k -= vp[ind].second;
			if (k <= 0) {
				cout << "NO" << "\n";
				return;
			}
		}else {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}
/*
int searchLeft(vector<pair<long long, long long>> vp, int s, int e, int tar) {
	int in = e + 1;
	while (s < e) {
		int mid = s + (e - s)/2;
		if (vp[mid].first == tar) {
			in = mid;
			e = mid - 1;
		}else if (vp[mid].first < tar) {
			s = mid + 1;
		}else e = mid - 1;
	}
	return in;
}
*/