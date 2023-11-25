#include<bits/stdc++.h>
using namespace std;
int t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
// #define ff first
// #define ss second
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}

//sol.
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ff = -1; int ss = -1; int flg = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') { ff = i; break; }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'B') {ss = i; break;}
    }
    if (ss == -1 || ff == -1) {
        cout << 0 << "\n";
        return;
    }
    cout << max((int)0, ss - ff) << "\n";
 }

    
    



