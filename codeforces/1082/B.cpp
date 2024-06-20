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
    vector<int> segg;
    s += 'S';
    int cnt = 1;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        if (s[i] == s[i+1] && s[i] == 'G') {
            cnt++;
        } else {
            if (s[i] == 'G') {
                segg.push_back(cnt);
                cnt = 1;
            }
        }
    }
    s.pop_back();
    s += 'G';
    vector<int> segs;
    for(int i = 0; i < n; i++) {
        if (s[i] == s[i+1] && s[i] == 'S') {
            cnt++;
        } else {
            if (s[i] == 'S') {
                segs.push_back(cnt);
                cnt = 1;
            }
        }
    }

    if (segg.size() == 0) {
        cout << 0 << "\n";
        return;
    } else if (segs.size() == 0) {
        cout << segg[0] << "\n";
        return;
    }

    int starts = (s[0] == 'S');
    if (starts) {
        if (segs.size() == 1) {
            if (segg.size() == 0) {
                cout << 0 << "\n";
            } else {
                cout << segg[0] << "\n";
            }
        } else {
            if (segg.size() == 1) {
                cout << segg[0] << "\n";
            } else {
                if (segg.size() == 2) {
                    if (segs[1] > 1) {
                        cout << max(segg[0] + 1, segg[1] + 1) << "\n";
                    } else {
                        cout << segg[0] + segg[1] << "\n";
                    }
                } else {
                    int mx = segg[0];
                    for(int i = 0; i < segg.size() - 1; i++) {
                        if (segs[i+1] > 1) {
                            mx = max(mx, segg[i] + 1);
                            mx = max(mx, segg[i+1] + 1);
                        } else {
                            if (segg.size() == 2) {
                                mx = max(mx, segg[i] + segg[i + 1]);
                            } else {
                                mx = max(mx, segg[i] + segg[i + 1] + 1);
                            }
                        }
                    }
                    if (segs.size() > segg.size()) {
                        mx = max(mx, segg[segg.size()-1] + 1);
                    }
                    cout << mx << "\n";
                }
            }
        }
    } else {
        if (segs.size() == 0 || segg.size() == 1) {
            cout << segg[0] << "\n";
        }else {
            int mx = segg[0];
            for(int i = 0; i < segg.size() - 1; i++) {
                if (segs[i] > 1) {
                    mx = max(mx, segg[i] + 1);
                    mx = max(mx, segg[i+1] + 1);
                } else {
                    if (segg.size() == 2) {
                        mx = max(mx, segg[i] + segg[i+1]);
                    } else {
                        mx = max(mx, segg[i] + segg[i+1] + 1);
                    }
                }
            }
            if (segs.size() == segg.size()) {
                mx = max(mx, segg[segg.size() - 1] + 1);
            }
            cout << mx << "\n";
        }
    }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}