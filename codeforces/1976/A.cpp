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
    bool dig = true;
    string t1, t2;
    int ind = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            t1 += s[i];
        } else {
            break;
        }
        ind = i;
    }


    bool ok = true;
    for(int i = ind+1; i < n; i++) {
        if (s[i] <= '9' && s[i] >= '0') ok = false;
        t2 += s[i];
    }


    if (!ok) {
        cout << "NO\n";
        return;
    }

    for(int i = 1; i < t1.size(); i++) {
        if (t1[i] < t1[i-1]) ok = false;
    }

    for(int i = 1; i < t2.size(); i++) {
        if (t2[i] < t2[i-1]) ok = false; 
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}