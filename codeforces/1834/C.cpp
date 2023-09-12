#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve();
int main () {
    int tt;
    cin >> tt;
    while (tt--) solve();    
}
void solve () {
    ll asdiff = 0;
    ll revdiff = 0;
    ll n; cin >> n;
    string s;
    string t;
    cin >> s >> t;

    bool flg1 = false;
    bool flg2 = false;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) break;
        if (i == n - 1) flg1 = true;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != t[n - 1 - i]) break;
        if (i == n - 1) flg2 = true;
    }

    if (flg1) {
        cout << 0 << "\n"; return;
    }
    if (flg2) {
        cout << 2 << "\n"; return;
    }

    for (int i = 0; i < n; i++) 
        if (s[i] != t[i]) asdiff++;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] != t[n - 1 - i]) revdiff++;

    ll mn = INT_MAX;
    if (asdiff % 2) 
    mn = min (mn, 2 * asdiff - 1);
    else mn = min(mn, 2 * asdiff);

    if (revdiff % 2)
    mn = min(mn, 2 * revdiff);
    else
    mn = min(mn, 2 * revdiff - 1);

    cout << mn << "\n";
}