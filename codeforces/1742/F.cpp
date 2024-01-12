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
    int n; cin >> n;
    map<char,int> mp1;
    multimap<char,int> mp2;
    char f = 'a';
    int as = 0, so = 0;
    int at = 0, to = 0;
    while (n--) {
        int w,k; string s; 
         cin >> w >> k >> s;
         if (w == 1) {
            for (auto &x : s) {
                if (x == 'a') as += k;
                else so = 1;
            }
         }else {
            for (auto &x : s) {
                if (x == 'a') at += k;
                else to = 1;
            }
         }

         if (to) {
            cout << "YES\n";
         } else if (so) {
            cout << "NO\n";
         } else {
            if (as < at) {
                cout << "YES\n";
            }else cout << "NO\n";
         }
    }
}
