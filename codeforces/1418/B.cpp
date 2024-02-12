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
       int n;
       cin >> n;
       vector<int> v(n);
       vector<int> pos(n);
       for (auto &x : v) cin >> x;
       for (auto &x : pos) cin >> x;
       
       vector<int> temp;
       for (int i = 0; i < n; i++) {
           if (pos[i] == 0) temp.push_back(v[i]);
       }
       sort(temp.rbegin(), temp.rend());
       int j = 0;
       for (int i = 0; i < n; i++) {
           if (pos[i] == 0) v[i] = temp[j++];
       }
       for (auto &x : v) cout << x << " "; cout << "\n";
}
