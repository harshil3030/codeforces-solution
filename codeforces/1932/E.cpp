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
    string s; cin >> s;
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += (s[i] - '0');
        a[i] = k;
    }   
    
    int carry = 0;
    for (int i = n-1; i >= 0; i--) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
    
    // cout << carry << "\n";
    int flg = 0;
    if (carry > 0) {
        cout << carry;
        flg = 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && flg == 0) { 
            continue;
        }
        cout << a[i]; 
        flg = 1;
    } cout << "\n";
}
