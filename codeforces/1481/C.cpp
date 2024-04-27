#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();
int t = 0;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    t++;
    int n,m; cin >> n >> m;
    vector<int> a(n),b(n);
    for(auto &x : b) cin >> x;
    for(auto &x : a) cin >> x;
    vector<int> c(m);
    for(auto &x : c) cin >> x;
    
    map<int, vector<int>> required;
    for (int i = 0; i < n; i++) {
        required[a[i]].push_back(i+1);
    }
    if (required[c[m-1]].size() == 0) {
        cout << "NO\n";
        return;
    }
    int ele = required[c[m-1]][0];
    map<int, vector<int>> getColored;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            getColored[a[i]].push_back(i+1);
        }
    }
    if(getColored[c[m-1]].size() > 0) ele = getColored[c[m-1]][0];
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        if (getColored[c[i]].size() > 0) {
            ans.push_back(getColored[c[i]].back());
            getColored[c[i]].pop_back();
        } else {
            ans.push_back(ele);
        }
    }
    for(auto &x : getColored) {
        if (x.second.size() > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto &x : ans) cout << x << " "; cout << endl;
}
