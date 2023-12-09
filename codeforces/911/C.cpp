#include <bits/stdc++.h>
using namespace std;
void solve();
int main () {
    int tt = 1;
    // int tt; cin >> tt;
    while (tt--) solve();
    return 0;
}
void solve() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    map<int, int> mp;
    mp[n1]++; mp[n2]++; mp[n3]++;
    if (mp[1] >= 1) {
        cout << "YES\n";
    } else if (mp[2] >= 2) {
        cout << "YES\n";
    } else if (mp[3] >= 3) {
        cout << "YES\n";
    } else if (mp[4] == 2 && mp[2] == 1){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}