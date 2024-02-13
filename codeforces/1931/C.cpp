// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
    for (int i = 0; i < n; i++) cin >> v[i];
    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    
    int ff = v[0];
    int ss = v[n-1];
    int in1 = 0; int in2 = n-1;
    for (int i = 0; i < n; i++) {
        if (v[i] == ff) {
        in1 = i;
        }else break;
    }

    for (int i = n-1; i >= 0; i--) {
        if (v[i] == ss) {
            in2 = i;
            }
        else break;
    }
    
    // cout << ff << " " << ss << "\n";
    
    if (in2 < in1) {
        cout << 0 << "\n";
        return;
    } 
    
    if (v[in1] == v[in2]) {
        in1++; in2--;
        cout << in2-in1+1 << "\n";
        return;
    }
    else if (v[in1] != v[in2]) {
        in1++;
        cout << min(n-in1, (in2)) << "\n";
    }
    
    
     
}
