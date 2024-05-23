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
    int n;
    cin >> n;
    vector<int> v(n*n);
    for(auto &x : v) cin >> x;
    if(n % 2 == 0) {
        map<int, int> freq;
        for(int i = 0; i < n*n; i++) {
            freq[v[i]]++;
        }
        for(auto &x : freq) {
            if (x.second % 4 != 0) {
                cout << "NO\n";
                return;
            }
        }

        sort(v.begin(), v.end());
        int ind = 0;
        vector<vector<int>> ans(n, vector<int> (n));
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < n/2; j++) {
                ans[i][j] = v[ind++];
                ans[i][n-1-j] = v[ind++];
                ans[n-1-i][j] = v[ind++];
                ans[n-1-i][n-1-j] = v[ind++];
            }
        }
        cout << "YES\n";
        for(auto &x : ans) {
            for(auto &y : x) {
                cout << y << " ";
            } cout << "\n";
        }
    } else {
        map<int, int> freq;
        int singlEle = -1;
        int one = 0;
        for(int i = 0; i < n*n; i++) {
            freq[v[i]]++;
        }
        for(auto &x : freq) {
            if (x.second % 2 == 1) {
                 singlEle = x.first;
                 one++;
            }
        }
        if (one != 1) {
            cout << "NO\n";
            return;
        }
        int cnt4 = 0;

        vector<int> tmp;
        for(auto &x : freq) {
            if (x.second >= 4) {
                cnt4 += (x.second/4);
                for(int j = 0; j < (x.second/4) * 4; j++) {
                    tmp.push_back(x.first);
                }
            }
        }
        if (cnt4 < (n/2)*(n/2)) {
            cout << "NO\n";
            return;
        }

        int ind = 0;
        vector<vector<int>> ans(n, vector<int> (n));
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < n/2; j++) {
                ans[i][j] = tmp[ind++];
                ans[i][n-1-j] = tmp[ind++];
                ans[n-1-i][j] = tmp[ind++];
                ans[n-1-i][n-1-j] = tmp[ind++];
            }
        }

        for(int i = 0; i < ind; i++) {
            freq[tmp[i]]--;
            if(freq[tmp[i]] == 0) {
                freq.erase(tmp[i]);
            }
        }
        ans[n/2][n/2] = singlEle;
        freq[singlEle]--;
        if(freq[singlEle] == 0) {
            freq.erase(singlEle);
        }
        vector<int> rest;

        for(auto &x : freq) {
            for(int j = 0; j < x.second; j++) {
                rest.push_back(x.first);
            }
        }
        sort(rest.begin(), rest.end());

        ind = 0;
        for(int i = 0; i < n/2; i++) {
            ans[n/2][i] = rest[ind++];
            ans[n/2][n-1-i] = rest[ind++];
            ans[i][n/2] = rest[ind++];
            ans[n-1-i][n/2] = rest[ind++];
        }

        cout << "YES\n";
        for(auto &x : ans) {
            for(auto &y : x) {
                cout << y << " ";
            } cout << "\n";
        }
    }  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}