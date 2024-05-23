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
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        freq[v[i]]++;
    }   

    if (freq.size() == 1) {
        if (m >= freq[v[0]]) {
            cout << (v[0] + min((m - (freq[v[0]] - 1)), k)) << "\n";
        } else {
            v[0] += m;
            double d = 0;
            for(auto &x : v) d += x;
            d/=n;
            prDouble(d);
            cout << "\n";
        }
        return;
    }


    
    int sm = 0;
    for(int i = 0; i < n; i++) {
        if (m > 0 && freq.size() > 2) {
            m--;
            freq[v[i]]--;
            if (freq[v[i]] == 0) {
                freq.erase(v[i]);
            }
        }
    }

    if (m == 0) {
        double d = 0;
        int cnt = 0;
        for(auto &x : freq) {
            for(int i  =0; i < x.second; i++) {
                d += x.first;
                cnt++;
            }
        }
        d /= cnt;
        prDouble(d);
        cout << "\n";
        return;
    }

    pair<int, int> ini = *freq.begin();
    pair<int, int> last = *freq.rbegin();
    int ff = ini.first;
    int fff  = ini.second;
    int ss = last.first;
    int ssf = last.second;

    if (ss - ff > 1) {
        int mn = min(fff, m);
        m -= mn;
        fff -= mn;
        if (fff == 0) {
                if (m >= ssf) {
                    cout << (ss + min((m - (ssf - 1)), k)) << "\n";
                    }
                 else {
                    double d = 0;
                    for(int i  =0; i < ssf; i++) d += ss;
                    d += m;
                    d/=ssf;
                    prDouble(d);
                    cout << "\n";
                }
            } else {
                m += mn;
                int tmp = m;
                double d = 0;
                for (int i = 0; i < ssf; i++) {
                    if (m == 0) {
                        break;
                    }
                    d += ss;
                    m--;
                    
                }

                for (int i = 0; i < fff; i++) {
                    if (m == 0) {
                        break;
                    }
                    m--;
                    d += ff;
                }

                d/=tmp;
                prDouble(d);
                cout << "\n";
            }  
    } else {
        if (fff > m) {
            double d = m;
            for(int i = 0; i < fff; i++) {
                d += ff;
            }
            for(int i = 0; i < ssf; i++) {
                d += ss;
            }
            d /= (fff + ssf);
            prDouble(d);
            cout << "\n";
        } else {
            m -= fff;
            fff = 0;

            if (m >= ssf) {
                m -= (ssf - 1);
                cout << ss + min(m, k) << "\n";
            } else {
                double d = m;
                for(int i = 0; i < ssf; i++) {
                    d += ss;
                }
                d /= ssf;
                prDouble(d);
                cout << "\n";
            }
        }
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}