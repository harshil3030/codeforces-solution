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
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    
    vector<int> temp;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        string t = to_string(v[i]);
        tot += t.length();
        int cnt = 0;
        for (int i = (t.length() - 1); i >=0; i--) {
            if (t[i] == '0') {
                cnt++;
            }else break;
        }
        // cout << t << " for : " << cnt << "\n";
        temp.push_back(cnt);
    }   
    
    sort(temp.rbegin(), temp.rend());
    
    // for (auto &x : temp) {
        // cout << x << " "; 
    // } cout << "\n";
    
    int removed = 0;
    for (int i = 0; i < n; i+=2) {
        removed += temp[i];
    }
    tot -= removed;
    if (tot > m) {
        cout << "Sasha\n";
    }else {
        cout << "Anna\n";
    }
}
