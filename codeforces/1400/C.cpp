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
int t = 0;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    t++;
    string s; cin >> s;
    int x; cin >> x;
    int n = s.length();
    
    vector<char> w(n);
    for (auto &x: w) x = '1';
    
    for (int i = 0; i < n; i++) {
        int left = i-(x);
        int right = i+(x);
        if (s[i] == '0') {
           if (left >= 0) w[left] = '0';
           if (right <= n-1) w[right] = '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
        bool one = false;
        one = one || (i - x >= 0 && w[i - x] == '1');
        one = one || (i + x < n && w[i + x] == '1');
 
        if (s[i] != one + '0') {
            cout << -1 << '\n';
            return;
            }            
        }
    
    
    
    
    for (auto &x : w) cout << x;
     cout << "\n";
  
}
