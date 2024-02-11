// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
    
    sort(v.begin(), v.end());
    int mx = 1;
    map<int, int> freq;
    for (int i = 0; i < n;i++) {
        freq[v[i]]++;
    }
    int last = 0;
    int cnt = 1;
    set<int> st;
    for (auto &x : v) st.insert(x);
    vector<int> temp;
    temp.insert(temp.end(), st.begin(), st.end());
    
    for (int i = 1; i < temp.size(); i++) {
        if (i >= last) {
            if (temp[i] - temp[last] < n) {
                mx = max(mx, (i - last) + 1);
            }else {
                last++;
            }
        }
    }
    cout << mx << "\n";
}
