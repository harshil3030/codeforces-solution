// Problem: E. Eat the Chip
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1921/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
    int r,c,x1,y1,x2,y2; cin >> r >> c >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2) {
        cout << "DRAW\n";
        return;
    }   
    if (y1 == y2) {
        if (abs(x1 - x2) % 2 == 0) {
            cout << "BOB\n";
            return;
        }else {
            cout << "ALICE\n";
            return;
        }
    }
    if (abs(y1 - y2) < 2) {
        if (abs(x1 - x2) % 2) {
            cout << "ALICE\n";
            return;
        }
    }

    if(abs(x1 - x2) % 2 == 0) {
        if (y2 > y1) {
            int sm = y1 - 1 + (y2 - y1);
            if (sm > abs(x1-x2)/2) {
                cout << "DRAW\n";
                return;
            }else {
                cout << "BOB\n";
                return;
            }
        }else {
            int sm = c - y1 + (y1 - y2);
            if (sm > abs(x1-x2)/2) {
                cout << "DRAW\n";
                return;
            }else {
                cout << "BOB\n";
                return;
            }
        }
    }else {
        double dl = (abs(x1 - x2) * 1.0)/2.0;
        int ff = ceil(dl);
        if (y1 > y2) {
            int sm = y2 - 1 + (y1 - y2);
            if (sm > ff) {
                cout << "DRAW\n";
                return;
            }else {
                cout << "ALICE\n";
                return;
            }
        }else {
            int sm = c - y2 + (y2 - y1);
            if (sm > ff) {
                cout << "DRAW\n";
                return;
            }else {
                cout << "ALICE\n";
                return;
            }
        }
    }

}