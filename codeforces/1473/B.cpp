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
    string s,t; cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int lcm = (n*m)/__gcd(n,m);
    
    int ff = 0, ss = 0;
    string final = "";
    for (int i = 0; i < lcm; i++) {
        if (s[ff % n] != t[ss % m]) {
            cout << -1 << "\n";
            return;
        }        
        final += s[ff % n];
        ff++, ss++;
    }
    cout << final << "\n";   
}

