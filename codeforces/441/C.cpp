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
    int n,m,k;
    cin >> n >> m >> k;
    int req = 2;
    int curr = 2;
    int count = 0;
    if (k == 1) curr = n*m;
    vector<vector<pair<int,int>>> ans;
    vector<pair<int, int>> taking;
    for(int i = 1; i <= n; i++) {

        if (i % 2) {
            for(int j = 1; j <= m; j++) {
                if (curr > 0) {
                    taking.push_back({i, j});
                    curr--;
                } else {
                    count++;
                    if (count == k-1) {
                        curr = n*m - (2*count);
                    } else curr = req;
                    ans.push_back(taking);
                    vector<pair<int,int>> tmp;
                    taking = tmp;
                    taking.push_back({i, j});
                    curr--;
                }
            }
        } else {
            for(int j = m; j >= 1; j--) {
                if (curr > 0) {
                    taking.push_back({i, j});
                    curr--;
                } else {
                    count++;
                    if (count == k-1) {
                        curr = n*m - (2*count);
                    } else curr = req;
                    ans.push_back(taking);
                    vector<pair<int, int>> tmp;
                    taking = tmp;
                    taking.push_back({i, j});
                    curr--;
                }
            }
        }

        if (curr == 0) {
            count++;
            if (count == k-1) {
                curr = n*m - (2*count);
            } else curr = req;
            ans.push_back(taking);
            vector<pair<int, int>> tmp;
            taking = tmp;
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j].first << " " << ans[i][j].second << " ";
        } cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}