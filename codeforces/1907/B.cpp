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
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------

void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> get(n, 0);
    int b = 0,B = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'b') { b++; }
        else if (s[i] == 'B'){ B++; }
        else if (s[i] >= 'a' && s[i] <= 'z' && s[i] != 'b') {
            if (b > 0) {get[i] = -1; b--;}
        }else if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'B') {
            if (B > 0) {get[i] = -1; B--;}
        }
    }
//    for (auto &x : get) cout << x << " "; cout << "\n";
    for (int i = 0; i < n; i++) {
        if (get[i] == 0 && (s[i] != 'b' && s[i] != 'B')) cout << s[i];
    }
    cout << "\n";
}
