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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i].first = v[i];
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[vp[i].first] = i;
    }
    int get[n];
    for (auto &x : get) x = 0;
    vector<set<int>> ans;
    for (int i = 0; i < n; i++) {
        if (get[i] == 0) {
            int j = i;
            set<int> st; st.insert(i);
            while (mp[v[j]] != i) {
                int x = mp[v[j]];
                get[x] = -1;
                st.insert(x);
                j = x;
            }
            ans.push_back(st);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        for (auto &x : ans[i]) cout << x + 1 << " ";
         cout << "\n";
    }
}


