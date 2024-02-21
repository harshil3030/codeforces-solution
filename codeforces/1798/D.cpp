#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
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
    
    vector<int> neg,pos,zeros;
    int flg = 1;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
             flg = 0;
             break;
        }
    }   
    if (flg) {
        cout << "NO\n";
        return;
    }
    
    
    for (auto &x : v) {
        if (x < 0) neg.push_back(x);
        if (x > 0) pos.push_back(x);
        if (x == 0) zeros.push_back(x);
    }
    
    
    int mx = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    vector<int> final;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int i = 0, j = 0;
    int sm = 0;
    while (i < neg.size() && j < pos.size()) {
        if (sm < 0) {
            final.push_back(pos[j]);
            sm += pos[j];
            if (abs(sm) >= mx) {
                cout << "NO\n";
                return;
            }
            j++;
        } else {
            final.push_back(neg[i]);
            sm += neg[i];
            if (abs(sm) >= mx) {
                cout << "NO\n";
                return;
            }
            i++;
        }
    }
    
    while (i < neg.size()) {
            sm += neg[i];
            final.push_back(neg[i]);
            if (abs(sm) >= mx) {
                cout << "NO\n";
                return;
            }
            i++;
    }
    
    while (j < pos.size()) {
        sm += pos[j];
        final.push_back(pos[j]);
        if (abs(sm) >= mx) {
            cout << "NO\n";
            return;
        }
        j++;
    }
    
    i = 0;
    while (i < zeros.size()) {
        final.push_back(0);
        i++;
    }
    
    cout << "YES\n"; 
    for (auto &x : final) cout << x << " "; cout << "\n";
    
}
