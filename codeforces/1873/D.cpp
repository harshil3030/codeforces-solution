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
		long long n, k; cin >> n >> k;
		string s; cin >> s;
		/*int cnt = 0; int sm = 0; 
		vector <int> diff;
		for (int i = 0; i < n; i++) 
			if (s[i] == 'B') diff.push_back(i);
		int in = diff[0];
		if (k == 1) cnt++;
		for (int i = 1; i < n; i++) {
			sm = diff[i] - in;
			if (sm > k){ 
			in = diff[i]; cnt++; 
			}
		}
		cout << cnt << '\n';*/
	int cnt = 0;
    vector<int> diff;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            diff.push_back(i);
        }
    }

    if (diff.empty()) {
        cout << 0 << '\n';
        return;
    }

    int in = diff[0];
    cnt++;

    for (int i = 1; i < diff.size(); i++) {
        int sm = diff[i] - in + 1;
        if (sm > k) {
            cnt++; in = diff[i];
        }
        
    }

    cout << cnt << '\n';
}
