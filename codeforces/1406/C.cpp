#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

int dfs(int v, int p, vector<vector<int>> &li, vector<int> &dp) {
    int sm = 0;
    for(auto &child : li[v]) {
        if (child == p) continue;
        int get = dfs(child, v, li, dp);
        sm += get;
        dp[v] = max(dp[v], get);
    }
    dp[v] = max(dp[v], (int)li.size()-1-sm);
    return sm + 1;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> li(n);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        li[n1].push_back(n2);
        li[n2].push_back(n1);
    }
    vector<int> dp(n, 0);
    int got = dfs(0, -1, li, dp);
    int mn = 1e9;
    for(int i = 0; i < n; i++) mn = min(mn, dp[i]);

    int cnt = 0;
    vector<int> tmp;
    for(int i = 0; i < n; i++) {
        if (dp[i] == mn) {
            cnt++;
            tmp.push_back(i);
        }
    }

    if (tmp.size() > 2) {
        assert(false);
    }
    if (tmp.size() == 1) {
        cout << tmp[0] + 1 << " " << li[tmp[0]][0] + 1 << "\n";
        cout << tmp[0] + 1 << " " << li[tmp[0]][0] + 1 << "\n";
    } else {
        int nxt = tmp[1];
        int give = -1;
        for(auto &child : li[tmp[0]]) {
            if (child != nxt) {
                give = child;
                break;
            }
        }
        cout << tmp[0] + 1 << " " << give + 1 << "\n";
        cout << tmp[1] + 1 << " " << give + 1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}