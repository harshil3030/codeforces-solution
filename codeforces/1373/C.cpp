#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    string s; cin >> s;
    int n = s.length();

    vector<int> get(n,0);
    int cntplus = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            get[i] = 1;
            cntplus++;
        } else if (s[i] == '-' && cntplus > 0) {
            get[i] = 1;
            cntplus--;
        }
    }   
    int cnt = 0;
    for (auto &x : get) if (x == 0) cnt++;
    cnt+=1;
    
    int ans = 0;
    int flg = 0;
    // for (auto &x : get) cout << x << " "; cout << "\n";
    for (int i = 0; i < n; i++) {
        if (get[i] == 1) {
            ans += cnt;
        }else {
            ans += cnt;
            cnt--;
        } 
    }
    cout << ans << "\n";
}
