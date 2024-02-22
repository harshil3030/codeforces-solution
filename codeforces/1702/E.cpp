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
int f = 0;
void dfs(int v, int c, vector<int> &color, vector<vector<int>> adj) {
    queue<int> q;
    q.push(v);
    color[v] = c;
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        
        for (auto &node: adj[top]) {
            if (color[node] == -1) {
                q.push(node);
                color[node] = color[top] ^ 1;
            } else if (color[node] == color[top]) {
                f++;
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (adj[x].size() > 2 || adj[y].size() > 2) {
            ok = false;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    
    vector<int> color(n+1, -1);
    
    bool flg = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            dfs(i, 0, color, adj);
            if (f > 0) {
                f = 0;
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
