#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    string e1 = "";
    string e2 = "";
    vector<pair<char, int>> vp;
    vector<pair<char, int>> vp2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'c'){
         e1 += s[i];
         vp.push_back({s[i], i});
     }
        if (t[i] == 'a' || t[i] == 'c') {
         e2 += t[i];
         vp2.push_back({t[i], i});
     }
    } 

    if (e1 == e2) {
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i].first == 'a' && vp[i].second > vp2[i].second) {
                cout << "NO\n";
                return;
            }
            if (vp[i].first == 'c' && vp[i].second < vp2[i].second) {
                cout << "NO\n";
                return;
            }
        }
    }else {
        cout << "NO\n";
        return;
    }
      cout << "YES\n";
}

