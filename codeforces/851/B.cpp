#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
//-----------------------------------------------------------------------
void solve();
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}
//-----------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() {
    int a1,a2,b1,b2,c1,c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    int dis = (abs(a1 - b1)) * (abs(a1 - b1)) + (abs(a2 - b2)) * (abs(a2 - b2));
    int dis2 = (abs(c1 - b1)) * (abs(c1 - b1)) + (abs(c2 - b2)) * (abs(c2 - b2));
    int dis3 = (abs(c1 - a1)) * (abs(c1 - a1)) + (abs(c2 - a2)) * (abs(c2 - a2));
    if ( (a1 - b1) * (b2 - c2) != (b1 - c1) *  (a2 - b2)     &&  dis == dis2) {
        cout << "Yes\n";
    } else cout << "No\n";
}


