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
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int day = 1;

    map<int, vector<int>> ind;
    map<int, int> indOfind;

    for(int i = 0; i < n; i++) {
        ind[v[i]].push_back(i);
    }

    vector<int> ans(n, 0);

    sort(v.begin(), v.end());
    int ff = 0;
    ans[ind[v[0]][indOfind[v[0]]]] = 1;
    indOfind[v[0]]++;
    int curr = 1;
    int mx = 1;

    int new_day = 2;
    while (curr < n) {
        while (curr < n && v[curr] - v[ff] <= d) {
            ans[ind[v[curr]][indOfind[v[curr]]]] = new_day;
            indOfind[v[curr]]++;
            new_day++;
            curr++;
        }
        if (curr >= n) break;

        ans[ind[v[curr]][indOfind[v[curr]]]] =  ans[ind[v[ff]][--indOfind[v[ff]]]];
        ++indOfind[v[ff]];
        ++indOfind[v[curr]];
        curr++;
        ff++;
    }

    for(auto &x : ans) mx = max(mx, x);
    cout << mx << "\n";
    for(auto &x : ans) {
        cout << x << " ";
    } cout << "\n";

//    while (curr < n) {
//        while (curr < n && v[curr] - v[ff] <= d) curr++;
//        if (curr >= n) break;
//
//        ans[ind[v[curr]][indOfind[v[curr]]]] = ans[ind[v[ff]][--indOfind[v[ff]]]];
//        indOfind[v[ff]]++;
//
//        ff++;
//        int lastans = ans[ind[v[ff]][indOfind[v[ff]]]];
//
//        if (lastans == 0) {
//            ans[ind[v[0]][indOfind[v[0]]]] = ans[ind[v[curr]][indOfind[v[curr]]]] + 1;
//            indOfind[v[0]]++;
//        }
//    }
//



    //    while (curr < n) {
//        while (curr < n && v[curr] - v[ff] <= d) curr++;
//        if (curr >= n) break;
//
//        int tmp = 2;
//        for(int i = ff + 1; i < curr; i++) {
//            ans[ind[v[i]][indOfind[v[i]]]] = tmp;
//            mx = max(mx, tmp);
//            tmp++;
//            indOfind[v[i]]++;
//        }
//
//        ans[ind[v[curr]][indOfind[v[curr]]]] = 1;
//        indOfind[v[curr]]++;
//
//        ff = curr;
//    }
//
//    if (ff != (n-1)) {
//        int tmp = 2;
//        for(int i = ff + 1; i < n; i++) {
//            ans[ind[v[i]][indOfind[v[i]]]] = tmp;
//            mx = max(mx, tmp);
//            tmp++;
//            indOfind[v[i]]++;
//        }
//    }
//
//    cout << mx << "\n";
//    for(auto &x : ans) {
//        cout << x << " ";
//    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}