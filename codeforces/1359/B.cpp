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
    int n,m,one,two; cin >> n >> m >> one >> two;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    if (2*one <= two) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '.') cnt += one;
            }
        }
        cout << cnt << "\n";
        return;
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0 && m > 1 && s[i][j + 1] == '.' && s[i][j] == '.') continue;
                if (j == 0 && s[i][j] == '.') cnt += one;

                if (j > 0 && j < m-1) {
                    if (s[i][j] == '.' && s[i][j-1] == '.') {
                        s[i][j] = '*';
                        s[i][j-1] = '*';
                        cnt += two;
                    } else if (s[i][j] == '.' && s[i][j + 1] == '.') {
                        cnt += two;
                        s[i][j] = '*';
                        s[i][j+1] = '*';
                    } else if (s[i][j] == '.') {
                        cnt += one;
                        s[i][j] = '*';
                    }
                }

                if (j == m-1 && j != 0) {
                    if (s[i][j-1] == '.' && s[i][j] == '.') {
                        cnt += two;
                        s[i][j] = '*';
                        s[i][j-1] = '*';
                    } else if (s[i][j] == '.') {
                        cnt += one;
                        s[i][j] = '*';
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}
