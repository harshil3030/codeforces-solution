#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
  int n,k;
  cin >> n >> k;
  string s; cin >> s;
  s += ((s[n-1]  == '0' ? '1' : '0'));
  int cnt = 1;
  vector<int> seg;
  for(int i = 0; i < n; i++) {
    if (s[i] == s[i+1]) {
      cnt++;
    } else {
      seg.push_back(cnt);
      cnt = 1;
    }
  }

  bool ok = true;
  int i = 0;
  for(int j = 0; j < seg.size(); j++) {
  	if (seg[j] != k) {
        i = j;
        ok = false;
        break;
    }
  }
  if (ok) {
  	cout << n << endl;
  	return;
  }

  bool get2k = false;
  // for(int i = 0; i < seg.size();i++) {
  	if (seg[i] == 2*k) {
  		get2k = true;
  		bool done = true;
  		for(int j = i+1; j  < seg.size(); j++) {
  			if (seg[j] != k) {
  				done = false;
  				break;
  			}
  		}

  		if (done) {
  			if ((i == seg.size() - 1) || (seg.size() - 1 - i) % 2 == 0) {
  				cout << -1 << endl;
  				return;
  			}
  			cout << k*(i+1) << endl;
  			return;
  		} else {
  			cout << -1 << endl;
  			return;
  		}
  	} else if (seg[i] + seg[seg.size() - 1] == 2*k && seg[i] > k) {
  		bool okk = true;
  		for(int j = i+1; j < seg.size() - 1; j++) {
  			if (seg[j] != k) okk = false;
  		}
  		if (!okk) {
  			cout << -1 << endl;
  			return;
  		}

  		if ((seg.size() - 1 - i) % 2 == 0) {
  			cout << k*i + (seg[i] - k) << endl;
  			return;
  		} else {
  			cout << -1 << endl;
  			return;
  		}
  	}  else if (seg[i] > k){
  		cout << -1 << endl;
  		return;
  	}
  // } 

  // for(int i = 0; i < seg.size(); i++) {
  	if (seg[i] < k) {
  		if (i == seg.size() - 1) {
  			cout << -1 << endl;
  			return;
  		}

  		bool okk = true;
  		for(int j = i+1; j < seg.size() - 1; j++) {
  			if (seg[j] != k) okk = false;
  		}
  		if (!okk) {
  			cout << -1 << endl;
  			return;
  		}

  		if (seg[i] + seg[seg.size() - 1] == k &&  (seg.size() - 1 - i) % 2 == 0 ) {
  			cout << k*i+seg[i] << endl;
  			return;
  		} else {
  			cout << -1 << endl;
  			return;
  		}
  	}
  // }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}