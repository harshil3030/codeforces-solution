#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> li(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        li[n1].push_back(n2);
        li[n2].push_back(n1);
    }
    vector<int> vis(n, 0);

    auto fun = [&](int curr) -> int {
       int cmp = 1;
       int edges = 0;

        queue<int> q;
        q.push(curr);
        vis[curr] = 1;
        edges += li[curr].size();
        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto &child : li[front]) {
                if (vis[child] == 0) {
                    cmp++;
                    edges += li[child].size() - 1;
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }

        return edges < cmp;
    };


    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            cnt += fun(i);
        }
    }
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}