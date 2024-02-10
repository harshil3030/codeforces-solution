// Problem: C. Closest Cities
// Contest: Codeforces - Educational Codeforces Round 161 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1922/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

void solve() {
    int n; cin >> n;
    vector<int> v(n); for (auto &x : v) cin >> x;

    vector<char> nearind(n);
    nearind[0] = 'r'; nearind[n-1] = 'l';
    for (int i = 1; i < n-1; i++) {
        int dis1 = abs(v[i] - v[i-1]);
        int dis2 = abs(v[i] - v[i+1]);

        if (dis1 > dis2) nearind[i] = 'r';
        else nearind[i] = 'l';
    }

    vector<int> left(n,0),right(n,0);

    int last = 1;
    for (int i = 0; i < n; i++) {
        if (nearind[i] == 'r') last = i + 1;
        left[i] = last;
    }

    last = n;
    for (int i = n-1; i >= 0; i--) {
        if (nearind[i] == 'l') last = i + 1;
        right[i] = last;
    }


// for (auto &x : left) cout << x << " "; cout << "\n";
// for (auto &x : right) cout << x << " "; cout << "\n";
// return;
    vector<int> finalright(n,0);
    for (int i = 1; i < n; i++) {
        if (nearind[i - 1] == 'r') {
            finalright[i] = 1 + finalright[i - 1];
        } else {
            finalright[i] = abs(v[i] - v[i - 1]) + finalright[i - 1];
        }
    }

    vector<int> finalleft(n,0);
    for (int i = n-2; i >= 0; i--) {
        if (nearind[i+1] == 'l') {
            finalleft[i] = finalleft[i+1] + 1;
        }else {
            finalleft[i] = finalleft[i+1] + abs(v[i] - v[i+1]);
        }
    }
int q; cin >> q;
while (q--) {
        int x,y; cin >> x >> y;
        if (x < y) {
            cout << abs(finalright[y-1] - finalright[x-1]) << "\n";
        }else {
            cout << abs(finalleft[x-1] - finalleft[y-1]) << "\n";
        }
    }
}