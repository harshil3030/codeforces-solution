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
    int n;
    cin >> n;
    if (n % 2 == 1 || n < 4) {
        cout << -1 << "\n";
        return;
    }


    if (n % 6 == 0) {
        cout << n/6 << " ";
    } else {
        if (n % 6 == 2) {
            cout << 2 + (n-8)/6 << " ";
        } else if (n % 6 == 4) {
            cout << 1 + (n-4)/6 << " ";
        } else {
            cout <<  -1 << "\n";
            return;
        }
    }




    if (n % 4 == 0) {
        cout << n/4 << " ";
    } else {
        if (n % 4 == 2) {
            cout << 1 + (n-6)/4 << " ";
        } else {
            cout << -1 << "\n";
            return;
        }
    }
    cout << "\n";
}
