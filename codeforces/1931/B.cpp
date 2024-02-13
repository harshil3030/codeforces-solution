// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
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
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    if (n == 1) {
        cout << "YES\n";
        return;
    }   
    
    double suff[n + 1];
    suff[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        suff[i] = suff[i+1] + v[i];
    }
    double sm = 0;
    for (int i = 0; i < n-1; i++) {
        sm += v[i];
        if (sm/(i+1) < suff[i+1]/(n-(i+1))) {
            cout << "NO\n";
            return;
        }
        
    }
    cout << "YES\n";
}
