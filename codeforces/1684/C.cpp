#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }   

    int in1 = m - 1,in2 = m - 1;
    for (int i = 0; i < n; i++) {
        multiset<int> ms1; int cnt = 0;
        for (int j = 0; j < m; j++) ms1.insert(v[i][j]);
        for (int j = 0; j < m; j++) {
            if (v[i][j] != *ms1.begin()) {
                cnt++;
                if (cnt == 1)
                in1 = j;
                else if (cnt == 2)in2 = j;
            }
            ms1.erase(ms1.begin());
        }
        if (cnt >= 2) {
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        swap(v[i][in1], v[i][in2]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (v[i][j] < v[i][j-1]) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << in1 + 1 << " " << in2 + 1 << "\n";
}
