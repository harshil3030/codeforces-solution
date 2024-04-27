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
  int n,k; cin >> n >> k;
    vector<vector<int>> li(n);
    vector<int> rem(n);
    for(int i = 0; i < n-1; i++) {
        int x,y; cin >> x >> y;
        x--,y--;
        li[x].push_back(y);
        li[y].push_back(x);
        rem[x]++, rem[y]++;
    }   
    vector<int> d(n,0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (li[i].size() == 1) {
            q.push(i);
            d[i] = 1;
        }
    }   
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto &child : li[top]) {
            rem[child]--;
            if(rem[child] == 1) {
                if (d[child] == 0) {
                    q.push(child);
                    d[child] = d[top] + 1;
                }
            }
        }
    }
    int ans = 0;
    for(auto &x : d) if (x > k) ans++;
    cout << ans << endl;
}
