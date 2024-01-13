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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    
    int pts = 0;
    int i = 0, r = n-1; int moves = 0;
    if (i <= r) {
        while (i < r) {
            if (v[i] + pts < v[r]) {
                pts += v[i];
                moves += v[i];
                i++;
            }else {
                moves += v[r] - pts + 1;
                v[i] -= v[r] - pts;
                r--;
                pts = 0;
            }
        }
        if (v[r] > pts) {
            int diff = v[r] - pts;
            if (diff % 2) {
                moves += diff/2 + 1;
                v[r] -= diff/2 + 1;
                pts += diff/2 + 1;
            }
            else {
                moves += diff/2;
                v[r] -= diff/2;
                pts += diff/2;
            }
        }
         if (v[r] <= pts && pts != 0 && v[r] >= 1) moves += 1;
    }  
    cout << moves << "\n";  
}