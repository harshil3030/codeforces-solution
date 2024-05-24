#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 998244353;

int color[2] = {0, 0};
bool bipartite(vector<vector<int>> &li, vector<int> &vis, vector<int> &c, int i) {
    queue<int> q;
    q.push(i);
    c[i] = 0;
    color[0]++;
    vis[i] = 1;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(auto &child : li[top]) {
            if (c[child] == -1) {
                vis[child] = 1;
                q.push(child);
                color[1^c[top]]++;
                c[child] = 1^c[top];
            } else if (c[child] == c[top]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }  

    bool ok = true;
    vector<int> vis(n, 0);
    vector<pair<int,int>> part;
    
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i-1] % mod) * 2;
        dp[i] %= mod;
    }
    vector<int> c(n, -1);

    for (int i = 0; i < n;i++) {
         if (vis[i] == 0) {
             ok &= bipartite(v, vis, c, i);
            
             part.push_back({color[0], color[1]});
             color[0] = 0;
             color[1] = 0;
        }
    }
    if (!ok) {
        cout << 0 << "\n";
        return;
    }
    int ans = 1;
    for (int i = 0; i < part.size(); i++) {
        int sum = dp[part[i].first] + dp[part[i].second];
        sum %= mod;
        ans = (ans % mod) * (sum % mod);
        ans %= mod;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}