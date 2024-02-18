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
    string s; cin >> s;
    int flg = 0;    
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == '*' && s[i+1] == '*') {
            flg = 1;
            break;
        }
        if (s[i] == '@') cnt++;
        
    }   
    
    if (!flg) {
        if (s[n-1] == '@') cnt++;
    }
    cout << cnt << "\n";
}
