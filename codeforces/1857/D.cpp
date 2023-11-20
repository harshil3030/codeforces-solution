#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
// #define ff    first
// #define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &y : b) cin >> y;
    vector<long long> sum(n);
    for (int i = 0; i < n; i++) sum[i] = b[i] - a[i];
    vector<long long> small; small = sum;
    // for (int i = 0; i < n; i++) cout << small[i] << " "; cout << "\n";
    sort(small.begin(), small.end());
    int ele1 = small[0];
    int ele2 = small[1];
    for (int i = 0; i < n; i++) {
        if (sum[i] == ele1) sum[i] = ele2;
        else sum[i] = ele1;
    }
    // cout << "here\n";
    // cout << ele1 << " " << ele2 << "\n";    

    vector<long long> cont;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i] - sum[i]) {
            cont.push_back(i + 1);
        }
    }
    cout << cont.size() << "\n";
    for (int i = 0; i < cont.size(); i++) cout << cont[i] << " "; cout << "\n";

}
