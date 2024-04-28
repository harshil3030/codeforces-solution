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
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int ans[n];
    map<int, int> mp;
    deque<int> dq;
    vector<int> getBy(n+1,-1);
    for(int i = 0; i < n; i++) {
        if (mp[v[i]] > 0) {
            ans[i] = -1;
        } else {
            ans[i] = v[i];
            getBy[v[i]] = i;
        }
        mp[v[i]]+=1;
    }

    for(int i = 1; i <= n; i++) {
        if (!mp[i]) dq.push_back(i); 
    }

    for(int i = 0; i < n; i++) {
        if (ans[i] != -1) continue;
        if (dq.front() == (i + 1)) {
            dq.pop_front();
            dq.push_back(i+1);
        }
        ans[i] = dq.front();
        dq.pop_front();
    }

    int last = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if (v[i] == ans[i]) {
          cnt++;
          continue;  
        } 
        if (i + 1 == ans[i]) {
            if (last == -1) {
                int u = ans[i];
                ans[i] = v[i];
                ans[getBy[v[i]]] = (i + 1);
            } else {
                swap(ans[last], ans[i]);
            }
        }

        last = i;
    }

    cout << cnt << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
