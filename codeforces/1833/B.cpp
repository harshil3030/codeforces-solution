#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------

//sol.
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        cin >> vp[i].first;
        vp[i].second = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(vp.begin(), vp.end());
    sort(b.begin(), b.end());

    map<int, int> mp;
    map<int, int> getind;
    for (int i = 0; i < n; i++) {
        mp[vp[i].second] = b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << mp[i] << " ";
    } cout << "\n";
}
