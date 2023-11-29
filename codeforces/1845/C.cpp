#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
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
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------

//sol.
void solve() {
    string s; cin >> s;
    int n = s.length();
    int m; cin >> m;
    string s1,s2; cin >> s1 >> s2;
    int mx = 0; int last = 0;
    for (int i = 0; i < m; i++) {
        int l = s1[i] - '0';
        int r = s2[i] - '0';
        int nmx = 0;
        for (int j = l; j <= r; j++) {
            int cur = last;
            while (cur < n && (s[cur] - '0') != j) cur++;
            nmx = max(nmx, cur);
        }
        last = nmx + 1;
    }
    if (last > n) {
        cout << "YES\n";
        return;
    }else {
        cout << "NO\n";
        return;
    }


    
}
