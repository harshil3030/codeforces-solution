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

void find(vector<int> ind) {
    // vector<int> biggcd;
    // vector<pair<int,int>> gcds;
    // int mx = -1;
//         
    // if (ind.size() > 2) {
        // for (int i = 1; i < ind.size(); i++) {
            // cout << "?" << " " << ind[0] << " " << ind[i] << "\n";
            // cout.flush();
            // int gd; cin >> gd;
            // gcds.push_back({gd,i});
            // if (gd > mx) {
                // mx = gd;
            // }
        // }
    // } else {
        // if (ind.size() == 2) {
            // cout <<"!" << " " << ind[0] << " " << ind[1] << "\n";
        // }
        // else {
            // cout << "!" << " " << ind[0] << " " << ind[0] << "\n"; 
        // }
        // cout.flush();
        // int ans; cin >> ans;
        // cout.flush();
        // return;
    // }
//     
     // for (int i = 0; i < gcds.size(); i++) {
         // if (gcds[i].first == mx) {
             // biggcd.push_back(ind[gcds[i].second]);
         // }
     // } 
//      
     // if (biggcd.size() == 1) {
         // cout << "!" << " " << ind[0] << " " << biggcd[0] << "\n";
         // cout.flush();
         // int ans; cin >> ans;
         // cout.flush();
         // return;
     // }
//      
     // biggcd.push_back(ind[0]);
//      
     // find(biggcd);  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    int l = 1, r = 2;
    for (int i = 3; i <= n; i++) {
        cout << "?" << " " << l << " " << i << "\n";
        cout.flush();
        int ql; cin >> ql;
        cout << "?" << " " << r << " " << i << "\n";
        cout.flush();
        int q2; cin >> q2;
        if (ql > q2) {
            r = i;
        }else if (q2 > ql) {
            l = i;
        }
    }
    cout << "!" << " " << l << " " << r << "\n";
    cout.flush();
    int ans; cin >> ans;
    cout.flush();
    
    // for (int i = 1; i <= n; i++) {
        // a.push_back(i);
    // }   
    // find(a);
}
