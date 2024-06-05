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
 int n,m;
 cin >> n >> m; 
 cout << "?" << " " <<  1 << " " << 1 << endl;
 int dis;
 cin >> dis;
 int upperx = -1, uppery = -1, lowerx = -1, lowery = -1;

 if (dis < m) {
    uppery = dis + 1;
    upperx = 1;
 } else {
    uppery = m;
    upperx = dis-m+2;
 }

 if(dis < n) {
    lowerx = dis + 1;
    lowery = 1;
 } else {
    lowerx = n;
    lowery = dis-n+2;
 }

 int dis2, dis3;
 cout << "?" << " " << upperx << " " << uppery << endl;
 cin >> dis2;
 
 cout << "?" << " " << lowerx << " " << lowery << endl;
 cin >> dis3;

 int dis4,dis5,dis6;
 int crossx, crossy, crossx2, crossy2;
 
 bool ok = false;
 if (dis2 % 2 == 0) {
    ok = true;
    int half = dis2/2;
    crossx = upperx + half;
    crossy = uppery - half;
    cout << "?" << " " << crossx << " " << crossy << endl;
    cin >> dis4;
    if (dis4 == 0) {
        cout << "!" << " " << crossx << " " << crossy << endl;
        return;
    } 
 }
 int half = dis3/2;
 crossx2 = lowerx - half;
 crossy2 = lowery + half;
 cout << "!" << " " << crossx2 << " " << crossy2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}