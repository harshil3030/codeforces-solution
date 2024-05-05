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
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }   

    auto check = [&](int i, int j) {
        if (i > 0 && j > 0) {
            int cnt = 0;
            cnt += s[i-1][j] == '1';
            cnt += s[i-1][j-1] == '1';
            cnt += s[i][j-1] == '1';
            if (cnt == 3) return true;
        } 
        if (i > 0 && j < m-1) {
            int cnt = 0;
            cnt += s[i-1][j] == '1';
            cnt += s[i-1][j+1] == '1';
            cnt += s[i][j+1] == '1';
            if (cnt == 3) return true;
        }
        if (i < n-1 && j > 0) {
            int cnt = 0;
            cnt += s[i+1][j] == '1';
            cnt += s[i+1][j-1] == '1';
            cnt += s[i][j-1] == '1';
            if (cnt == 3) return true;
        }
        if (i < n-1 && j < m-1) {
            int cnt = 0;
            cnt += s[i+1][j] == '1';
            cnt += s[i+1][j+1] == '1';
            cnt += s[i][j+1] == '1';
            if (cnt == 3) return true;
        }
        return false;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '0') {
                bool ok = check(i,j);
                if (ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";



    // auto check  = [&](int i, int j) -> set<pair<int, int>> {
    //     int cnt = 0;
    //     int last = cnt;
    //     set<pair<int, int>> st;
    //     if (i > 0) {
    //         cnt += s[i-1][j] == '1' ? 1 : 0;
    //         if (cnt > last) st.insert({i-1,j});
    //         last = cnt;
    //     }
    //     if (j > 0) {
    //         cnt += s[i][j-1] == '1' ? 1 : 0;
    //         if (cnt > last) st.insert({i,j-1});
    //         last = cnt;
    //      }   
    //     if (i < n-1) {
    //         cnt += s[i+1][j] == '1' ? 1 : 0;
    //         if (cnt > last) st.insert({i+1,j});
    //         last = cnt;
    //     } 
    //     if (j < m-1) {
    //         cnt += s[i][j+1] == '1' ? 1 : 0;
    //         if (cnt > last) st.insert({i,j+1});
    //         last = cnt;
    //     }
    //     return st;
    // };
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(s[i][j] == '1') {
    //             int cnt = 0;
    //             set<pair<int, int>> temp = check(i,j);
    //             bool ok = true;
    //             if(temp.size() == 1) {
    //                 pair<int, int> ff = *temp.begin();
    //                 int x = ff.first;
    //                 int y = ff.second;
    //                 if (x < i) {
    //                     if (y > 0) {
    //                         if (s[x][y-1] == '1') ok = false;
    //                     } 
    //                     if (y < m - 1) {
    //                         if (s[x][y+1] == '1') ok = false;
    //                     }
    //                 } else if (x > i) {
    //                     if (y > 0) {
    //                         if (s[x][y-1] == '1') ok = false;
    //                     } 
    //                     if (y < m - 1) {
    //                         if (s[x][y+1] == '1') ok = false;
    //                     }
    //                 } else if (y > i) {
    //                     if (x > 0) {
    //                         if (s[x-1][y] == '1') ok = false;
    //                     } 
    //                     if (x < n-1) {
    //                         if (s[x+1][y] == '1') ok = false;
    //                     }
    //                 } else {
    //                     if (x > 0) {
    //                         if (s[x-1][y] == '1') ok = false;
    //                     } 
    //                     if (x < n-1) {
    //                         if (s[x+1][y] == '1') ok = false;
    //                     }
    //                 }
    //             }
    //             if (!ok) {
    //                 cout << "NO\n";
    //                 return;
    //             }
    //         }
    //     }
    // }
    // cout << "YES\n";
}
