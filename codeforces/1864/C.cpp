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
    long long n; cin >> n;
    vector<int> cont;
    cont.push_back(n);
    if (n % 2) {
        cont.push_back(n - 1);
        n--;
    }
    auto bin_expo = [&](long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2) {
                ans = ans * a;
            }
            b/=2;
            a = a * a;
        }
        return ans;
    };
    string s = "";
    long long temp = n;
    while (temp > 0) {
        if (temp % 2) s += "1";
        else s += "0";
        temp /= 2;
    }
    reverse(s.begin(), s.end());
    long long in = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            in = i; break;
        }
    }
    in++;
    temp = n;
    long long len = s.length();
    for (int i = len - 1; i >= in; i--) {
        if (s[i] == '1') {
            temp -= bin_expo(2, len - i - 1);
            cont.push_back(temp);
        }
    }

    for (int i = in; i < len; i++) {
        temp -= bin_expo(2, len - i - 1);
        cont.push_back(temp);
    }
    cout << cont.size() << "\n";
    for (int i = 0; i < cont.size(); i++) cout << cont[i] << " ";
        cout << "\n";

}
