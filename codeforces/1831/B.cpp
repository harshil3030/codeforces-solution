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
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() { 
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    a.push_back(0);
    b.push_back(0);
    map<int, int> mp;
    int cnt[2*n + 1];
    for (auto &x : cnt) {
        x = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            mp[a[i]]++;
        }else {
            cnt[a[i]] = max(cnt[a[i]], mp[a[i]] + 1);
            mp[a[i]] = 0;
        }
    }
    mp.clear();
    int cnt2[2*n + 1];
    for (auto &x : cnt2) x = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == b[i + 1]) {
            mp[b[i]]++;
        } else {
            cnt2[b[i]] = max(cnt2[b[i]], mp[b[i]] + 1);
            mp[b[i]] = 0;
        }
    }
    int mx = 1;
    for (int i = 1; i <= 2*n; i++) {
        mx = max(mx, cnt[i] + cnt2[i]);
    }
    cout << mx << "\n";
}


