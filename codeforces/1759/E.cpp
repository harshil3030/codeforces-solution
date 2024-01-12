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
    int n,h; cin >> n >> h;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int g = 2, b = 1;
    int i = 0;
    int flg = 0, flg2 = 0;
    int temp = h;
    int res1 = -1, res2 = -1;
    while (i < n) {
        if (v[i] < temp) {
            temp += v[i]/2;
        }else if (v[i] >= temp) {
            while (v[i] >= temp) {
                if (g > 0) {g--;
                    temp *= 2;
                }else if (b > 0){ b--;
                    temp *= 3;
                }else {
                    res1 = i;
                    flg = 1;
                    break;
                }
            }
            if (flg == 1) {
                break;
            }
            temp += v[i]/2;
        } 
        i++;
    }
    if (res1 == -1) res1 = n;
   flg = 0;
   temp = h; i = 0; b = 1, g = 2;
    while (i < n) {
        if (v[i] < temp) {
            temp += v[i]/2;
        }else if (v[i] >= temp) {
            while (v[i] >= temp) {
                if (b > 0) {b--;
                    temp *= 3;
                }else if (g > 0){ g--;
                    temp *= 2;
                }else {
                    res2 = i;
                    flg = 1;
                    break;
                }
            }
            if (flg == 1) {
                break;
            }
            temp += v[i]/2;
        } 
        i++;
    }
    if (res2 == -1) res2 = n; 
    int res3 = -1;

   flg = 0;
   temp = h; i = 0; b = 1, g = 2;
    while (i < n) {
        if (v[i] < temp) {
            temp += v[i]/2;
        }else if (v[i] >= temp) {
            while (v[i] >= temp) {  
                if (g > 1){
                  g--; temp *= 2;
                }else if (b > 0) {b--;
                    temp *= 3;
                }else if (g > 0){ g--;
                    temp *= 2;
                }else {
                    res3 = i;
                    flg = 1;
                    break;
                }
            }
            if (flg == 1) {
                break;
            }
            temp += v[i]/2;
        } 
        i++;
    }
    if (res3 == -1) res3 = n;
    cout << max(res1, max(res2,res3)) << "\n";
    // cout << max(res1, res2) << "\n";
}
 