#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
//void dfs(int v, int p, vector<vector<int>> &li, vector<vector<int>> &dp, vector<int> &a, int &k, vector<int> &vis) {
//    vis[v] = 1;
//    //first provide the information to child
//    for(auto &child : li[v]) {
//        for(int i = 0; i <= k; i++) {
//            dp[child][i] = min(dp[child][i], dp[v][i] + 1);
//        }
//    }
//
//    for(auto &child : li[v]) {
//        if (child != p && vis[child] == 0) {
//            dfs(child, v, li, dp, a, k, vis);
//        }
//    }
//
//    //take the information from child
//    for(auto &child : li[v]) {
//        for(int i = 0; i <= k; i++) {
//            dp[v][i] = min(dp[v][i], dp[child][i] + 1);
//        }
//    }
//}


void solve() {
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> li(n);
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        li[n1].push_back(n2);
        li[n2].push_back(n1);
    }

    vector<vector<int>> dp(n, vector<int> (k + 1,1e9));

    for(int i = 0; i < n; i++) {
        dp[i][a[i]] = 0;
    }
    vector<int> vis(n, 0);
    
    //the reason why k is small, is to do bfs multiple times with covering all vertexes exactly once for type = t,
    //start from source and go till cover all the vertexes only once, no need to go where value is already assigned and to verify 
    //weather it is small or not, it must be smaller dist if it is assigned earlier, because it's been captured by active node with 
    //low distance!
    
    for(int t = 1; t <= k; t++) {
        vector<int> q;
        for(int i = 0; i < n; i++) {
            if (t == a[i]) {
                q.push_back(i);
            }
        }

        for(int j = 0; j < q.size(); j++) {
            for(auto &child : li[q[j]]) {
                if (dp[child][t] == 1e9) {
                    dp[child][t] = dp[q[j]][t] + 1;
                    q.push_back(child);
                    //size will also increase with this so it will cover all the possible child
                }
            }
        }
    }

    for(int i = 0; i < n ;i++) {
        int sm = 0;
        sort(dp[i].begin(), dp[i].end());
        for(int l = 0; l < s; l++) sm += dp[i][l];
        cout << sm << " ";
    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}