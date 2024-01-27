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
    int n,m; cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "YES\n";
        cout << 1 << "\n";
        return;
    } else {
        if (m == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) 
                cout << i << "\n";
        } else {
            if (n % 2) {
                cout << "NO\n";
                return;
            } else {
                cout << "YES\n";
                int cnt = 1;
                int res[n][m];
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        res[j][i] = cnt++;
                    }
                }

                for (auto &x : res) {
                    for (auto &y : x) cout << y << " ";
                    cout << "\n";
                }
            }
        }
    }   
}
