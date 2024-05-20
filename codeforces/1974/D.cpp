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
	int n;
	cin >> n;
	string s;
	cin >> s;

	if (s == "EW" || s == "WE" || s == "NS" || s == "SN") {
		cout << "NO\n";
		return;
	}
	int w = 0, no = 0, e = 0, so = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == 'N') no++;
		if (s[i] == 'S') so++;
		if (s[i] == 'E') e++;
		if (s[i] == 'W') w++;
	}  
	int mne = min(e, w);
	e -= mne;
	w -= mne;

	if (e % 2 != 0 || w % 2 != 0) {
		cout << "NO\n";
		return;
	}

	int mns = min(so, no);
	so -= mns;
	no -= mns;

	if (so % 2 != 0 || no % 2 != 0) {
		cout << "NO\n";
		return;
	}

	int mnw = mne;
	int mnn = mns;
	int tmp2 = mnw;

	int tmp1 = mns;
	bool re = true;
	bool rw = true;
	bool rs = true;
	bool rn = true;
	string final = s;
	for(int i = 0; i < n; i++) {
		if (s[i] == 'E') {
			if (mne > 0) {
				mne--;
			} else {
				if (re) {
					final[i] = 'R';
					re = false;
				} else {
					final[i] = 'H';
					re = true;
				}
			}
		}

		if (s[i] == 'W') {
			if (mnw > 0) {
				mnw--;
			} else {
				if (rw) {

					final[i] = 'R';
					rw = false;
				} else {
					final[i] = 'H';
					rw = true;
				}
			}
		}

		if (s[i] == 'N') {
			if (mnn > 0) {
				mnn--;
			} else {
				if (rn) {

					final[i] = 'R';
					rn = false;
				} else {
					final[i] = 'H';
					rn = true;
				}
			}
		}

		if (s[i] == 'S') {
			if (mns > 0) {
				mns--;
			} else {
				if (rs) {

					final[i] = 'R';
					rs = false;
				} else {
					final[i] = 'H';
					rs = true;
				}
			}
		}
	}
	

	if (tmp1 && tmp2) {
		for(int i = 0; i < n; i++) {
			if (final[i] == 'S' || final[i] == 'N') {
				final[i] = 'R';
			} else if (final[i] == 'W' || final[i] == 'E') {
				final[i] = 'H';
			}
		}
	} else if (tmp1) {
		bool rs = true;
		bool rn = true;
		for(int i = 0; i < n; i++) {
			if (final[i] == 'S') {
				if (rs) {
					rs = false;
					final[i] = 'R';
				} else {
					rs = true;
					final[i] = 'H';
				}
			} else if (final[i] == 'N') {
				if (rn) {
					rn = false;
					final[i] = 'R';
				} else {
					rn = true;
					final[i] = 'H';
				}
			}
		}
	} else if (tmp2) {
		bool rs = true;
		bool rn = true;
		for(int i = 0; i < n; i++) {
			if (final[i] == 'E') {
				if (rs) {
					rs = false;
					final[i] = 'R';
				} else {
					rs = true;
					final[i] = 'H';
				}
			} else if (final[i] == 'W') {
				if (rn) {
					rn = false;
					final[i] = 'R';
				} else {
					rn = true;
					final[i] = 'H';
				}
			}
		}
	}

	cout << final << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}