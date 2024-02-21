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
    for (auto &x  :v) cin >> x;
    m--;
    
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i-1];
    }
    
    int pm = pref[m+1];
    int in = m;
    priority_queue<int> pq;
    pq.push(v[in]);
    in--;
    
    int ans = 0;
    while (in >= 0) {
        if (pref[in + 1] < pm) {
            int sm = pm-pref[in + 1];
            while (sm > 0) {
                sm -= pq.top();
                pm -= 2*pq.top();
                pq.pop();
                ans++;
            }
        }
        pq.push(v[in]);
        in--;
    }   
    
    priority_queue<int,vector<int>, greater<int>> mpq;
    in = m+1;
    pm = pref[m+1];
    while (in < n) {
        mpq.push(v[in]);
        if (pref[in + 1] < pm) {
            int sm = pm - pref[in + 1];
            while (sm > 0) {
                sm += mpq.top();
                pm += 2*mpq.top();
                mpq.pop();
                ans++;
            }
        }
        in++;
    }
    cout << ans << "\n";
}
