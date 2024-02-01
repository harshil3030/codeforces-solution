#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

set<int> st;

void dfs1(int u, int last, int w, vector<vector<pair<int,int>>>& adj, int b) {
    if (u == b) return;
    st.insert(w);
    for (auto &x : adj[u]) {
        if (x.first == last) continue;
        dfs1(x.first, u, (w^x.second), adj, b);
    }
}

bool dfs2(int u, int last, int w, vector<vector<pair<int, int>>>& adj, int b) {
    if (u != b && st.count(w)) return true;
    for (auto &x : adj[u]) {
        if (x.first == last) continue;
        if (dfs2(x.first, u, w^(x.second), adj, b)) return true;
    }
    return false;
}

void solve() {
    st.erase(st.begin(), st.end()); // Clear the set for each test case
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < n-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dfs1(a, -1, 0, adj, b);

    if (dfs2(b, -1, 0, adj, b)) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
