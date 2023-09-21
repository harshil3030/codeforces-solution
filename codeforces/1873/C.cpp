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
		vector <string> v(10); int n = 10;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		/*
		if (x1 > n/2 && y1 > n/2) {
		return max(abs(x1 - (n/2 + 1)) , abs(y1 - (n/2 + 1)));
	}else if (x1 > n/2) {
		return max(abs(x1 - (n/2 + 1)) , abs(y1 - (n/2)));
	}else if (y1 > n/2) {
		return max(abs(x1 - (n/2)) , abs(y1 - (n/2 + 1)));
	}else {
		return max(abs(x1 - (n/2)) , abs(y1 - (n/2)));		
	}*/
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 'X') {
					if (i >= 5 && j >= 5) {
						cnt += 10 - max(i, j);
					}else if (i >= 5 && j < 5) {
						cnt += min(10 - i, j + 1);
					}else if (i < 5 && j < 5) {
						cnt += min(i, j) + 1;
					}else cnt += min(i + 1, 10 - j);
				}
			}
		}
		cout << cnt << "\n";

}
