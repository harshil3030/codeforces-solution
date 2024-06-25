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
    int n,p;
    cin >> n >> p;
    p--;
    string s;
    cin >> s;

    int tot_transform = 0;
    vector<int> ind;
    for(int i = 0; i < n/2; i++) {
        char ff = s[i];
        char la = s[n-1-i];
        if (ff == la) {
            continue;
        }
        ind.push_back(i);
        if (la < ff) swap(la, ff);
        tot_transform += min(abs(la-ff), ('z' - la) + (ff - 'a') + 1);
    }

    if (ind.size() == 0) {
        cout << tot_transform << "\n";
        return;
    }
    if (p == n/2 && n % 2 == 1) {
        p--;
        tot_transform++;
    }
    if (p >= n/2) {
        p = n-1-p;
    }
    int ff = ind[0];
    int la = ind[ind.size()-1];
    if (ff == la) {
        cout << abs(ff-p)+tot_transform << "\n";
        return;
    } else {
        if (ff <= p && la <= p) {
            cout << abs(p-ff) + tot_transform << "\n";
        } else if (ff >= p && la >= p) {
            cout << abs(la-p) + tot_transform << "\n";
        } else {
            int mn_side = min(p-ff, la-p);
            mn_side*=2;
            int mx_side = max(p-ff,la-p);
            cout << mx_side + mn_side + tot_transform << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}